let text = ReasonReact.string;

let calculateWinner = squares => {
  let lines = [|
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6],
  |];

  let winner = ref(None);
  for (i in 0 to Array.length(lines) - 1) {
    let [a, b, c] = lines[i];
    if (squares[a] === squares[b] && squares[a] === squares[c]) {
      winner := squares[a];
    };
  };
  winner^;
};

[@react.component]
let make = () => {
  let (squares, setSquares) = React.useState(() => Array.make(9, None));
  let (nextPlayer, setNextPlayer) = React.useState(() => "X");
  let (status, setStatus) =
    React.useState(() => "Next player: " ++ nextPlayer);

  React.useEffect(() => {
    let winner = calculateWinner(squares);
    switch (winner) {
    | None => setStatus(_status => "Next player: " ++ nextPlayer)
    | Some(winner) => setStatus(_status => "Winner: " ++ winner)
    };
    None;
  });

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
    <div className="status"> {text(status)} </div>
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