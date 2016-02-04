var functionfactory = require('./build/Release/xmsbridge');
var asyncWorker = require('./build/Release/xmsbridgeAsync');
var http = require('http');

var options = {
  host: 'localhost',
  path: '/',
  //since we are listening on a custom port, we need to specify it by hand
  port: '9099',
  //This is what changes the request to a POST request
  method: 'POST'
};

var callback = function(response) {
  
    console.log("success");
}

var messageListener1 = functionfactory.CreateListenerConfig(
  "ServCon","localhost","1414","QM_idea_PC","queue://sample","theThree",
  function(err,val){
      console.log("dandanakka");
      console.log(val);
      var req = http.request(options, callback);
      req.write(val);
      req.end();
  });

functionfactory.StartListener(messageListener1);

var messageListener2 = functionfactory.CreateListenerConfig(
  "ServCon","localhost","1414","QM_idea_PC","queue://default","Musketeer",
  function(err,val){
      console.log("dandanakka2");
      console.log(val);
  });

functionfactory.StartListener(messageListener2);

asyncWorker.asyncReceiver("ServCon","localhost","1414","QM_idea_PC","queue://postcard",function(err,val){
   console.log(val);
});

 
var server = http.createServer(function(request, response) {
  console.log("Done here");
  response.writeHead(200, { "Content-Type": "text/plain" });
  response.end("Good");
	response = null;
});
 
console.log("Starting up the server");
server.listen(9099);
//var status = functionfactory.PrintConfig(messageListener);
/*console.log(messageConsumer("ServCon","localhost","1414","QM_idea_PC","queue://sample", function(err,val){
	console.log(err);
	console.log(val);
}));

console.log("me first");*/
