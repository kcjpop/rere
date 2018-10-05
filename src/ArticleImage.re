let component = ReasonReact.statelessComponent("ArticleImage");

let make = (~title: string, ~image: option(string), _children) => {
  ...component,
  render: _self => {
    let src =
      switch (image) {
      | Some(src) => src
      | None => "http://placekitten.com/480/300"
      };

    <img className="w-full" src alt=title />;
  },
};