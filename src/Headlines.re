type state = {
  articles: NewsData.articles,
  loading: bool,
};

type action =
  | Loading
  | Loaded(NewsData.articles);

let component = ReasonReact.reducerComponent("Headlines");

let make = _children => {
  ...component,
  initialState: () => {articles: [||], loading: true},
  reducer: (action, state) =>
    switch (action) {
    | Loading => ReasonReact.Update({...state, loading: true})
    | Loaded(articles) => ReasonReact.Update({loading: false, articles})
    },
  didMount: self => {
    self.send(Loading);
    Js.Promise.(
      NewsData.fetchTopHeadlines(~country="us")
      |> then_((res: NewsData.response) => {
           self.send(res.articles->Loaded);
           resolve();
         })
      |> ignore
    );
  },
  render: self =>
    <div className="px-2 max-w-2xl mx-auto">
      <h1> {ReasonReact.string("Headline")} </h1>
      <div className="flex flex-wrap">
        {
          if (Array.length(self.state.articles) > 0) {
            self.state.articles
            |> Array.map((article: NewsData.article) =>
                 <Article key={article.url} article />
               )
            |> ReasonReact.array;
          } else {
            ReasonReact.null;
          }
        }
      </div>
    </div>,
};