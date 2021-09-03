"use strict";

require("dotenv").config();
const { Membership } = require('../../models'); 
const { Like } = require('../../models'); 
const { Job } = require('../../models');
const moment = require('moment');
const sequelize = require("sequelize");
const { and } = sequelize.Op;
const crypto = require('crypto');

/* GET /api/mypage/like */
exports.getLikelist = async (req, res) => {
    //마이페이지 - 저장목록에서 로그인한 유저의 좋아요 리스트 보여주기 
    const loggedID = res.locals.userid;
    const cardList = [];
    console.log("this is getLikelist");
    console.log({ "좋아요 페이지" : loggedID}); //test

    try{
        const jobList = await Like.findAndCountAll(
            { where: {userid: loggedID}, attributes: ['wantedAuthNo'] }
        );
        for(var i=0; i<jobList.count; i++){
            cardList.push(await toCard(jobList.rows[i].wantedAuthNo));
        }
        res.send(cardList);
    } catch (e) {
        console.error(e);
        res.status(500).send(); //500
    } 
};


const getData = async(wantedAuthNo) => {
    const job = await Job.findByPk(wantedAuthNo);
    return { job }
  }

const toCard = async(wantedAuthNo) => {
    const { job } = await getData(wantedAuthNo);
    return {
        wantedAuthNo: job.wantedAuthNo,
        wantedTitle: job.wantedTitle,
        company: job.company,
        logo: job.logo,
        receiptCloseDt: job.receiptCloseDt,
        jobCont: job.jobCont,
        likeNo: job.likeNo
    }
}

/* GET /api/mypage/profile */
exports.getProfile = async (req, res) => {
    const loggedID = res.locals.userid;
    console.log("this is getProfile");
    try{
        const member = await Membership.findByPk(loggedID)
        const profile = {
            name: member.realname,
            born: member.born,
            email: member.email,
            id: member.userid
        }
        res.status(201).send(profile);
    } catch(e){
        console.error(e);
        res.status(500).send();
    }
}


/* PUT /api/mypage/profile */
exports.editProfile = async (req, res) => {
    //마이페이지 - 프로필 관리에서 로그인한 유저 정보의 수정사항 저장
    const client = req.body;
    const loggedID = res.locals.userid;
    console.log("this is editProfile");

    if(client.psword !== client.confirmPsword) //412: 비밀번호 확인 실패
        return res.status(412).send(); 
    try {
        const {hashedPW, salt} = await createHashedPW(client.psword); //암호화

        await Membership.update(   
            {realname: client.name, 
                email: client.email,
                born: client.born,
                password: hashedPW, //암호화된 비밀번호
                salt: salt //salt
            },
            {where: {userid: loggedID} 
        })
        .then((result) => {
            res.status(201).send({ result });
        })
        .catch((err) => {
            console.log("editProfile Error: ", err);
        });
    }catch (e) {
        console.error(e);
        res.status(500).send(); //500
    } 
};

const createSalt = () =>
//Salt 반환
    new Promise((resolve, reject) => {
        crypto.randomBytes(64, (err, buffer) => {
            if (err){
                console.log("createSalt Error: ", err);
                reject(err);
            }
            resolve(buffer.toString('base64'));
        });
    });

const createHashedPW = (realPW) =>
//clientPw를 해싱하여 psword와 Salt 반환
    new Promise(async (resolve, reject) =>{
        const salt = await createSalt();

        crypto.pbkdf2(realPW, salt, 9999, 64, 'sha512', (err,key) =>{
            if (err){
                console.log("createHashedPW Error: ", err);
                reject(err);
            }
            resolve({hashedPW: key.toString('base64'), salt});
        })
    })


    

/* GET /api/mypage/notification */
exports.getDday = async (req, res) => {
    const loggedID = res.locals.userid;
    console.log("this is getDday");
    try{
        const member = await Membership.findByPk(loggedID)
        let dDay = {}
        if(member.alert === 0){
            dDay = {
                ifNotif: false,
                notifDay: 0
            }
        }
        else if (member.alert !== 0){
            dDay = {
                ifNotif: true,
                notifDay: member.alert
            }
        }
        res.status(201).send(dDay);
    } catch(e){
        console.error(e);
        res.status(500).send();
    }
}

/* POST /api/mypage/notification */
exports.notifyDday = async (req, res) => {
    //마이페이지- 디데이알림
    const { ifNotif, notifDay } = req.body;
    const loggedID = res.locals.userid;
    console.log("this is notifyDday");
    let likeList = []
    try{
        if (ifNotif === "false"){
            const member = await Membership.update({ alert: 0 }, { where: { userid: loggedID }})
            await Like.update({alertDate: "9999-01-01"}, {where: { userid: loggedID }})
        }
        else if (ifNotif === "true"){
            const member = await Membership.update({ alert: notifDay }, { where: { userid: loggedID }})
            likeList = await Like.findAll({ attributes: ['wantedAuthNo'], where: { userid: loggedID } })
            for(const like of likeList){
                const job = await Job.findOne({ attributes: ['receiptCloseDt'], where: {wantedAuthNo: like.wantedAuthNo} })
                if(job.receiptCloseDt === "9999-01-01"){
                    const update = await Like.update({alertDate: moment("9999-01-01", "YYYY-MM-DD")}, { where: {[and]: [{ userid: loggedID }, { wantedAuthNo: like.wantedAuthNo }]} })
                }
                else{
                    const receiptCloseDt = moment(job.receiptCloseDt, 'YYYY-MM-DD');
                    const alertMoment = receiptCloseDt.subtract(notifDay, 'days');
                    await Like.update({ alertDate: moment(alertMoment).format('YYYY-MM-DD') }, { where: {[and]: [{ userid: loggedID }, { wantedAuthNo: like.wantedAuthNo }]} })
                }
            }
        }
        else{
            res.status(400).send();
        }
        res.status(200).send()
    } catch(e){
        console.error(e)
        res.status(500).send();
    }
};

