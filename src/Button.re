let component = ReasonReact.statelessComponent("Button");

let make = (~onClick, children) => {
  ...component,
  render: _self =>
    <button
      onClick
      className="mx-1 bg-blue hover:bg-blue-dark text-white py-2 px-4 rounded text-sm">
      ...children
    </button>,
};