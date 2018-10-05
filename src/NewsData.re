let apiUrl = "https://newsapi.org/v2";

let topHeadlinesUrl = (~country) => {j|$apiUrl/top-headlines?country=$country|j};

type source = {
  id: string,
  name: string,
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
      id: json |> field("id", string),
      name: json |> field("name", string),
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

let data = {|
  {"status":"ok","totalResults":10,"articles":[{"source":{"id":"bbc-news","name":"BBC News"},"author":"BBC News","title":"Chinese tech shares hit by spyware row","description":"Shares in Lenovo and ZTE drop after a report that Beijing inserted spying devices into US computers.","url":"http://www.bbc.co.uk/news/business-45756685","urlToImage":"https://ichef.bbci.co.uk/news/1024/branded_news/E4C2/production/_103726585_ztephone_getty.jpg","publishedAt":"2018-10-05T11:05:48Z","content":"Image copyright Getty Images Shares in Chinese tech giants Lenovo and ZTE have fallen sharply after a media report that Beijing had inserted spying devices into US computers. Unnamed US national security officials, quoted by Bloomberg, said microchips were fo… [+1095 chars]"},{"source":{"id":"bbc-news","name":"BBC News"},"author":"BBC News","title":"Briton killed by sea snake in Australia","description":"The 23-year-old, thought to be a backpacker, was bitten on a fishing trawler, authorities say.","url":"http://www.bbc.co.uk/news/world-australia-45755135","urlToImage":"https://ichef.bbci.co.uk/news/1024/branded_news/3E82/production/_103720061_gettyimages-157879308.jpg","publishedAt":"2018-10-05T10:42:46Z","content":"Image copyright Getty Images Image caption Sea snakes are often encountered by fishing crews in northern Australia A British man has died after being bitten by a sea snake on a fishing trawler in Australia, police have said. The man, 23, thought to be a backp… [+1771 chars]"},{"source":{"id":"bbc-news","name":"BBC News"},"author":"BBC News","title":"Feely finger phone crawls across desk","description":"A fleshy finger phone accessory that can tickle its owner has been developed in France.","url":"http://www.bbc.co.uk/news/technology-45760646","urlToImage":"https://ichef.bbci.co.uk/news/1024/branded_news/E008/production/_103725375_mediaitem103725374.jpg","publishedAt":"2018-10-05T10:07:36Z","content":null},{"source":{"id":"bbc-news","name":"BBC News"},"author":"BBC News","title":"Missing Saudi writer gets blank column","description":"The Washington Post says it fears for Jamal Khashoggi, who vanished after entering a Saudi consulate.","url":"http://www.bbc.co.uk/news/world-us-canada-45758096","urlToImage":"https://ichef.bbci.co.uk/news/1024/branded_news/9F1C/production/_103723704_mediaitem103723702.jpg","publishedAt":"2018-10-05T09:18:13Z","content":"Image copyright Washington Post Image caption The blank column appears online and in the print edition The Washington Post has printed a blank column in support of its missing Saudi contributor Jamal Khashoggi. Mr Khashoggi - a critic of Saudi Crown Prince Mo… [+3230 chars]"},{"source":{"id":"bbc-news","name":"BBC News"},"author":"BBC News","title":"Toyota car fault prompts massive recall","description":"The firm is recalling more than 2.4 million vehicles to fix a fault that may cause them to lose power.","url":"http://www.bbc.co.uk/news/business-45756676","urlToImage":"https://ichef.bbci.co.uk/news/1024/branded_news/B9B6/production/_103724574_prius-64-plate-006_toyota.jpg","publishedAt":"2018-10-05T08:14:55Z","content":"Image copyright Toyota Japanese car giant Toyota has announced a recall of more than 2.4 million hybrid vehicles worldwide because of a fault in their systems that could cause them to lose power. The recall of Prius and Auris cars includes 1.25 million in Jap… [+1180 chars]"},{"source":{"id":"bbc-news","name":"BBC News"},"author":"BBC News","title":"South Korea ex-leader jailed for 15 years","description":"Convicted of bribery and abuse of power, Lee Myung-bak is the country's fourth leader to be jailed.","url":"http://www.bbc.co.uk/news/world-asia-45756561","urlToImage":"https://ichef.bbci.co.uk/news/1024/branded_news/8BE4/production/_103721853_049083278.jpg","publishedAt":"2018-10-05T07:04:16Z","content":"Image copyright AFP/Getty Image caption Former president Lee Myung-bak arriving at court in Seoul in September Former South Korean president Lee Myung-bak has been jailed for 15 years for corruption. Lee was sentenced in a Seoul court on Friday on charges of … [+955 chars]"},{"source":{"id":"bbc-news","name":"BBC News"},"author":"BBC News","title":"Captain America actor to 'retire' from role","description":"Chris Evans tweets that it's been \"an honour\" to play \"Cap\", after finishing filming Avengers 4.","url":"http://www.bbc.co.uk/news/newsbeat-45756235","urlToImage":"https://ichef.bbci.co.uk/news/1024/branded_news/D0A4/production/_103721435_smaller.jpg","publishedAt":"2018-10-05T05:49:53Z","content":"Image copyright Alamy It looks like Chris Evans - the actor who plays Captain America in the Marvel movies - is giving up the role after seven years. He's played him in 10 films, starting with Captain America: The First Avenger. Chris portrayed one of the ori… [+2418 chars]"},{"source":{"id":"bbc-news","name":"BBC News"},"author":"BBC News","title":"Musk mocks regulator days after settlement","description":"Tesla boss takes to Twitter days after reaching a deal with the Securities and Exchange Commission.","url":"http://www.bbc.co.uk/news/business-45754299","urlToImage":"https://ichef.bbci.co.uk/news/1024/branded_news/126B0/production/_102904457_hi048578541.jpg","publishedAt":"2018-10-05T00:25:40Z","content":"Image copyright Reuters Elon Musk has mocked a US financial regulator just days after reaching an agreement with it over fraud charges. The Tesla boss tweeted the \"Shortseller Enrichment Commission\", as he dubbed the Securities and Exchange Commission (SEC), … [+1613 chars]"},{"source":{"id":"bbc-news","name":"BBC News"},"author":"BBC News","title":"Hundreds arrested in Supreme Court protest","description":"Angry scenes as Brett Kavanaugh edges closer to winning confirmation for the US Supreme Court.","url":"http://www.bbc.co.uk/news/world-us-canada-45754771","urlToImage":"https://ichef.bbci.co.uk/images/ic/1024x576/p06mz2n2.jpg","publishedAt":"2018-10-05T00:20:34Z","content":"Media caption Protestors take to Capitol Hill Hundreds of protesters against US President Donald Trump's Supreme Court nominee have been arrested as the judge inched closer to confirmation. Police said 302 people were detained as Republicans declared that an … [+4612 chars]"},{"source":{"id":"bbc-news","name":"BBC News"},"author":"BBC News","title":"Girl pulls 1,500-year-old sword from lake","description":"Eight-year-old Saga Vanecek found a pre-Viking-era relic while playing in a lake in Sweden.","url":"http://www.bbc.co.uk/news/world-europe-45753455","urlToImage":"https://ichef.bbci.co.uk/news/1024/branded_news/15902/production/_103722388_d0c23635-6379-4bf7-bac8-478493c2d1c7.jpg","publishedAt":"2018-10-04T21:18:52Z","content":"Image copyright Jonkoping county museum An eight-year-old found a pre-Viking-era sword while swimming in a lake in Sweden during the summer. Saga Vanecek found the relic in the Vidostern lake while at her family's holiday home in Jonkoping County. The sword w… [+1290 chars]"}]}
|};

let s = data->Json.parseOrRaise->Decode.toResponse;