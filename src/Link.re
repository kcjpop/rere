let component = ReasonReact.statelessComponent("Link");

let handleClick = (href, e) =>
  if (!e->ReactEvent.Mouse.defaultPrevented) {
    e->ReactEvent.Mouse.preventDefault;
    ReasonReact.Router.push(href);
  };

let make = (~className, ~href, children) => {
  ...component,
  render: _self =>
    <a className href onClick={handleClick(href)}> ...children </a>,
};