var PATH = process.env.VD_PATH;
var path = require('path');
const config = require(path.resolve(PATH, 'algorithm/config'));

var so_path = config.so_path;

function testModule(func, callback) {
	try {
		var ret = func();
		if (ret != null)
			console.log(ret);
	}
	catch (err) {
		console.log(err);
		return callback(err);
	}
	callback(null);
}

module.exports = {
	so_path: so_path,
	testModule: testModule
}
