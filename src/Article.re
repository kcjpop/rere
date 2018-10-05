let component = ReasonReact.statelessComponent("Article");

let make = (~article: NewsData.article, _children) => {
  ...component,
  render: _self =>
    <article className="p-3 w-1/3">
      <div className="max-w-sm rounded overflow-hidden shadow-lg">
        <ArticleImage image={article.urlToImage} title={article.title} />
        <div className="px-6 py-4">
          <div className="font-bold text-xl mb-2">
            {ReasonReact.string(article.title)}
          </div>
          <p className="text-grey-darker text-base">
            {
              switch (article.description) {
              | Some(str) => ReasonReact.string(str)
              | None => ReasonReact.null
              }
            }
          </p>
          <div className="flex items-center mt-3">
            <div className="text-sm">
              <p className="text-grey-dark">
                {ReasonReact.string(article.publishedAt)}
              </p>
            </div>
          </div>
        </div>
      </div>
    </article>,
};