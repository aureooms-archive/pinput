var pinput = require('./pinput');
console.log(pinput.parse(process.argv, {'-v':1, '-h':1, '--help':1}));