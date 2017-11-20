var ffi = require("ffi");
console.log("in");

var api = ffi.Library("../lib/api.so", {
	"Create" : ["string", ["string", "string", "string"]],
	"Delete" : ["string", []],
	"Connect" : ["string" , ["string", "string", "string", "string"]],
	"Disconnect" : ["string" , ["string", "string", "string", "string"]],
	"GetValue" : ["string" , ["string", "string", "int", "int"]],
	"Run" : ["string" , ["string"]],
});
console.log("out");

var param = {
	"path" : "./test.csv",
	"column": 4,
	"column_type" : ["int", "int", "int", "string"],
	"contain_name" : 0,
	"filetype": "csv",
	"specify_name": 0,
};

console.log(param);
console.log("transfer to string");
console.log(JSON.stringify(param));
var message = api.Create("input1", "input", JSON.stringify(param));
console.log(message);
message = api.Run("input1");
console.log(message);
