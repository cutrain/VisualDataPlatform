var PATH = process.env.VD_PATH;
var path = require('path');
var so_path = path.resolve(PATH, 'algorithm');
var test_path = path.resolve(PATH, 'test');

module.exports = {
	PATH: PATH,
	so_path: so_path,
	test_path: test_path
}
