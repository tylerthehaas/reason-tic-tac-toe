let text = ReasonReact.string;

[@react.component]
let make = () =>
  <div className="game">
    <div className="game-board"> <Board /> </div>
    <div className="game-info" />
  </div>;