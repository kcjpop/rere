// Generated by BUCKLESCRIPT VERSION 4.0.5, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Link$ReactTemplate = require("./Link.bs.js");
var Counter$ReactTemplate = require("./Counter.bs.js");
var Greeting$ReactTemplate = require("./Greeting.bs.js");
var Headlines$ReactTemplate = require("./Headlines.bs.js");

var component = ReasonReact.reducerComponent("SimpleRouter");

function reducer(action, _) {
  return /* Update */Block.__(0, [/* record */[/* route */action[0]]]);
}

function mapUrlToRoute(url) {
  var match = url[/* path */0];
  if (match) {
    switch (match[0]) {
      case "counter" : 
          if (match[1]) {
            return /* NotFound */3;
          } else {
            return /* Counter */1;
          }
      case "headlines" : 
          if (match[1]) {
            return /* NotFound */3;
          } else {
            return /* Headlines */2;
          }
      default:
        return /* NotFound */3;
    }
  } else {
    return /* Home */0;
  }
}

function make() {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */(function (self) {
              var watcherId = ReasonReact.Router[/* watchUrl */1]((function (url) {
                      return Curry._1(self[/* send */3], /* ChangeRoute */[mapUrlToRoute(url)]);
                    }));
              return Curry._1(self[/* onUnmount */4], (function () {
                            return ReasonReact.Router[/* unwatchUrl */2](watcherId);
                          }));
            }),
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              var match = self[/* state */1][/* route */0];
              var tmp;
              switch (match) {
                case 0 : 
                    tmp = ReasonReact.element(undefined, undefined, Greeting$ReactTemplate.make("An", /* array */[]));
                    break;
                case 1 : 
                    tmp = ReasonReact.element(undefined, undefined, Counter$ReactTemplate.make(/* array */[]));
                    break;
                case 2 : 
                    tmp = ReasonReact.element(undefined, undefined, Headlines$ReactTemplate.make(/* array */[]));
                    break;
                case 3 : 
                    tmp = React.createElement("h1", undefined, "Not Found");
                    break;
                
              }
              return React.createElement("div", {
                          className: "m-3"
                        }, React.createElement("ul", {
                              className: "list-reset flex"
                            }, React.createElement("li", {
                                  className: "mr-6"
                                }, ReasonReact.element(undefined, undefined, Link$ReactTemplate.make("text-blue hover:text-blue-darker", "/", /* array */["Home"]))), React.createElement("li", {
                                  className: "mr-6"
                                }, ReasonReact.element(undefined, undefined, Link$ReactTemplate.make("text-blue hover:text-blue-darker", "/headlines", /* array */["Headlines"]))), React.createElement("li", {
                                  className: "mr-6"
                                }, ReasonReact.element(undefined, undefined, Link$ReactTemplate.make("text-blue hover:text-blue-darker", "/counter", /* array */["Counter"]))), React.createElement("li", {
                                  className: "mr-6"
                                }, ReasonReact.element(undefined, undefined, Link$ReactTemplate.make("text-blue hover:text-blue-darker", "/404", /* array */["Not Found"])))), React.createElement("main", {
                              className: "mt-5"
                            }, tmp));
            }),
          /* initialState */(function () {
              return /* record */[/* route : Home */0];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */reducer,
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.reducer = reducer;
exports.mapUrlToRoute = mapUrlToRoute;
exports.make = make;
/* component Not a pure module */
