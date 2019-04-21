let text = ReasonReact.string;

[@react.component]
let make = () => {
  let (squares, setSquares) = React.useState(() => Array.make(9, None));
  let (nextPlayer, setNextPlayer) = React.useState(() => "X");
  let handleClick = i => {
    setSquares(squares =>
      Array.mapi(
        (index, v) =>
          i == index
            ? switch (v) {
              | None => Some(nextPlayer)
              | Some(_str) => None
              }
            : v,
        squares,
      )
    );
  };
  let renderSquare = i =>
    <Square
      value={
        switch (squares[i]) {
        | None => ""
        | Some(str) => str
        }
      }
      onClick={_ => {
        handleClick(i);
        setNextPlayer(nextPlayer => nextPlayer == "X" ? "O" : "X");
      }}
    />;
  <div>
    <div className="status"> {text("Next player: " ++ nextPlayer)} </div>
    <div className="board-row">
      {renderSquare(0)}
      {renderSquare(1)}
      {renderSquare(2)}
    </div>
    <div className="board-row">
      {renderSquare(3)}
      {renderSquare(4)}
      {renderSquare(5)}
    </div>
    <div className="board-row">
      {renderSquare(6)}
      {renderSquare(7)}
      {renderSquare(8)}
    </div>
  </div>;
};