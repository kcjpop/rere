let apiUrl = "https://newsapi.org/v2";

let topHeadlinesUrl = (~country) => {j|$apiUrl/top-headlines?country=$country&apiKey=dd87847a99f145368ab6fad5194ce99d|j};

type source = {
  id: option(string),
  name: option(string),
};

type article = {
  source,
  author: option(string),
  title: string,
  description: option(string),
  url: string,
  urlToImage: option(string),
  publishedAt: string,
  content: option(string),
};

type articles = array(article);

type response = {
  status: string,
  totalResults: int,
  articles,
};

module Decode = {
  let toSource = json =>
    Json.Decode.{
      id: json |> optional(field("id", string)),
      name: json |> optional(field("name", string)),
    };

  let toArticle = json =>
    Json.Decode.{
      source: json |> field("source", toSource),
      author: json |> optional(field("author", string)),
      title: json |> field("title", string),
      description: json |> optional(field("description", string)),
      url: json |> field("url", string),
      urlToImage: json |> optional(field("urlToImage", string)),
      publishedAt: json |> field("publishedAt", string),
      content: json |> optional(field("content", string)),
    };

  let toArticles = json: articles => Json.Decode.(json |> array(toArticle));

  let toResponse = json =>
    Json.Decode.{
      status: json |> field("status", string),
      totalResults: json |> field("totalResults", int),
      articles: json |> field("articles", toArticles),
    };
};

let fetchTopHeadlines = (~country) =>
  Js.Promise.(
    Fetch.fetch(topHeadlinesUrl(~country))
    |> then_(Fetch.Response.json)
    |> then_(json => json |> Decode.toResponse |> resolve)
  );