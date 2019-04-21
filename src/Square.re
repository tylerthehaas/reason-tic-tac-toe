let text = ReasonReact.string;

[@react.component]
let make = (~value, ~onClick) => {
  <button className="square" onClick> {text(value)} </button>;
};