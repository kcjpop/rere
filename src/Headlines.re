type state = {
  articles: NewsData.articles,
  country: string,
  loading: bool,
};

type action =
  | Loading
  | Loaded(NewsData.articles)
  | ChangeCountry(string);

let component = ReasonReact.reducerComponent("Headlines");

let fetchTopHeadlines = self => {
  self.ReasonReact.send(Loading);
  Js.Promise.(
    NewsData.fetchTopHeadlines(~country=self.ReasonReact.state.country)
    |> then_((res: NewsData.response) =>
         self.ReasonReact.send(Loaded(res.articles)) |> resolve
       )
    |> ignore
  );
};

let doChangeCountry = (country, self) =>
  self.ReasonReact.send(ChangeCountry(country));

let make = _children => {
  ...component,
  initialState: () => {
    articles: [||],
    loading: true,
    country: Countries.list[0],
  },
  reducer: (action, state) =>
    switch (action) {
    | ChangeCountry(country) =>
      ReasonReact.UpdateWithSideEffects(
        {...state, country},
        fetchTopHeadlines,
      )
    | Loading => ReasonReact.Update({...state, loading: true})
    | Loaded(articles) =>
      ReasonReact.Update({...state, loading: false, articles})
    },
  didMount: self => fetchTopHeadlines(self),
  render: self =>
    <div className="px-2 max-w-2xl mx-auto">
      <div className="flex items-center justify-between">
        <h1> {ReasonReact.string("Headline")} </h1>
        <div className="flex items-center">
          {ReasonReact.string("Change country:")}
          <Dropdown
            onChange={self.handle(doChangeCountry)}
            items=Countries.list
          />
        </div>
      </div>
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