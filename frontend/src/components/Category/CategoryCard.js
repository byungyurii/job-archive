import React from "react";
import CardBoard from "../Card/CardBoard";
import "../../style/main.css";

function CategoryCard(props) {
  return (
    <div>
      {console.log(props.jobs)}
          <CardBoard jobs={props.jobs} islogin={props.islogin} />
    </div>
  );
}

export default CategoryCard;
