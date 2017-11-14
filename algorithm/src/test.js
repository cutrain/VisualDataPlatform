var ffi = require("ffi");

var api = ffi.Library("./api", {
	"Create" : ['string', ['string', 'string', 'string'] ],
	"Delete" : ['string', ['string'] ],
	"Connect" : ['string', ['string', 'string', 'string', 'string'] ],
	"Disconnect" : ['string', ['string', 'string', 'string', 'string'] ],
	"GetValue" : ['string', ['string', 'string', 'int', 'int'] ],
	"Run" : ['string', ['string', 'string'] ],
	"RunTo" : ['string', ['string'] ],
	"RunAll" : ['string', [] ],
});

var message = api.Create("input1", "input", "path:'.'");
console.log(message);
message = api.Create("input1", "input", "path:'.'");
console.log(message);
message = api.Delete("input1");
console.log(message);
message = api.Delete("input1");
console.log(message);
message = api.Create("input1", "input", "path:'.'");
console.log(message);
message = api.Connect("input1", "output", "input2", "input");
console.log(message);
message = api.Create("input2", "input", "path:'.'");
console.log(message);
message = api.Connect("input1", "output", "input2", "input");
console.log(message);
message = api.Disconnect("input1", "output", "input2", "input");
console.log(message);
message = api.Disconnect("input1", "output", "input2", "input");
console.log(message);


