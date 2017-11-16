var path = require('path');

var ffi = require('ffi');

var lib = require('./common.js');


var misc = ffi.Library(path.resolve(lib.so_path, 'misc'), {
	"min": [ 'double', [ 'double', 'double' ] ]
});

lib.testModule(function test() {
	var ans = misc.min(1.7, 1.8);
	if (ans != 1.7)
		return "expect 1.7 get " + ans;
}, function callback(err) {
}
)

