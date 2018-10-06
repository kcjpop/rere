let component = ReasonReact.statelessComponent("CountryDropdown");

let handleChange = (handler, e) => handler(e->ReactEvent.Form.target##value);

let make = (~onChange, ~items: array(string), _children) => {
  ...component,
  render: _self =>
    <select onChange={handleChange(onChange)}>
      {
        items
        |> Array.map(country =>
             <option key=country value=country>
               {ReasonReact.string(country)}
             </option>
           )
        |> ReasonReact.array
      }
    </select>,
};