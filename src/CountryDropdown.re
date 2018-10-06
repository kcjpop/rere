let component = ReasonReact.statelessComponent("CountryDropdown");

let countries = [|
  "ae",
  "ar",
  "at",
  "au",
  "be",
  "bg",
  "br",
  "ca",
  "ch",
  "cn",
  "co",
  "cu",
  "cz",
  "de",
  "eg",
  "fr",
  "gb",
  "gr",
  "hk",
  "hu",
  "id",
  "ie",
  "il",
  "in",
  "it",
  "jp",
  "kr",
  "lt",
  "lv",
  "ma",
  "mx",
  "my",
  "ng",
  "nl",
  "no",
  "nz",
  "ph",
  "pl",
  "pt",
  "ro",
  "rs",
  "ru",
  "sa",
  "se",
  "sg",
  "si",
  "sk",
  "th",
  "tr",
  "tw",
  "ua",
  "us",
  "ve",
  "za",
|];

let make = (~onChange, _children) => {
  ...component,
  render: _self =>
    <select onChange>
      {
        countries
        |> Array.map(country =>
             <option key=country value=country>
               {ReasonReact.string(country)}
             </option>
           )
        |> ReasonReact.array
      }
    </select>,
};