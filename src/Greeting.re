let component = ReasonReact.statelessComponent("Greeting");

let make = (~name, _children) => {
  ...component,
  render: _self =>
    <div>
      <h1> {ReasonReact.string("Hello World")} </h1>
      <div className="foo"> {ReasonReact.string(string_of_int(123))} </div>
      <button> {ReasonReact.string("Hello" ++ name)} </button>
    </div>,
};