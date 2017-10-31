var PATH = process.env.VD_PATH;
var path = require('path');
const config = require(path.resolve(PATH, 'config'));

var so_path = config.so_path;

function testModule(func) {
	var ret = func();
	if (ret != null)
		console.log(ret);
}

module.exports = {
	so_path: so_path,
	testModule: testModule
}
