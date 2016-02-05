var functionfactory = require('./build/Release/xmsbridge');
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
        var connection = functionfactory.connectionWrapper("ServCon","localhost","1414","QM_idea_PC","queue://default");
        functionfactory.startConnection(connection);
        callback(null, connection);
    },
    destroy  : function(connection) { functionfactory.closeConnection(connection); },
    max      : 10,
    // optional. if you set this, make sure to drain() (see step 3)
    min      : 1,
    // specifies how long a resource can stay idle in pool before being removed
    idleTimeoutMillis : 30000,
     // if true, logs via console.log - can also be a function
    log : true
});

var callback = function(response) {
      console.log("success");
}

var server = 
      http.createServer(function(request, response) {
                      pool.acquire(function(err, connection) {
                      if (err) {
                          // handle error - this is generally the err from your
                          // factory.create function  
                          console.log("connection not available");
                          response.writeHead(200, { "Content-Type": "text/plain" });
                          response.end("...............Bad");
                          response = null;
                      }
                      else {
                              var msg = functionfactory.receiveMessage(connection);
                              console.log(msg);
                              console.log("Done here");
                              response.writeHead(200, { "Content-Type": "text/plain" });
                              response.end("...............Good");
                              response = null;
                              pool.release(connection);
                      }
                  });
    });
 
console.log("Starting up the server");
server.listen(9099);

