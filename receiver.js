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

var Pool = require('generic-pool').Pool;

var pool = new Pool({
    name     : 'ibmmqxms',
    create   : function(callback) {
        var Client = require('mysql').Client;
        var c = new Client();
        c.user     = 'scott';
        c.password = 'tiger';
        c.database = 'mydb';
        c.connect();

        // parameter order: err, resource
        // new in 1.0.6
        callback(null, c);
    },
    destroy  : function(client) { client.end(); },
    max      : 10,
    // optional. if you set this, make sure to drain() (see step 3)
    min      : 2,
    // specifies how long a resource can stay idle in pool before being removed
    idleTimeoutMillis : 30000,
     // if true, logs via console.log - can also be a function
    log : true
});

var callback = function(response) {
      console.log("success");
}

var server = http.createServer(function(request, response) {
  asyncWorker.asyncReceiver("ServCon","localhost","1414","QM_idea_PC","queue://default",function(err,val){
     console.log("so so so");
     console.log("Done here");
     response.writeHead(200, { "Content-Type": "text/plain" });
     response.end("...............Good");
	   response = null;
  });
});
 
console.log("Starting up the server");
server.listen(9099);

