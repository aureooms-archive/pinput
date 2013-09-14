module.exports = {
	parse : function(argv, flags){
		var argc = argv.length;
		var res = {
			'parameter' : [],
			'optional' : {},
			'flag' : {}
		};


		var optionalParameterKey = '';
		var isOptionalParameter = false;

		for(var i = 2; i < argc; ++i){
			var arg = argv[i];
			if(arg[0] == '-'){
				isOptionalParameter = false;
				if(arg.length > 1){
					if(arg[1] == '-' || arg.length == 2){
						if(arg in flags){
							res['flag'][arg] = 1;
						}
						else{
							res['optional'][arg] = [];
							optionalParameterKey = arg;
							isOptionalParameter = true;
						}
					}
					else{
						for(var j = 1; j < arg.length; ++j){
							res['flag']['-'+arg[j]] = 1;
						}
					}
				}
			}
			else if(isOptionalParameter){
				res['optional'][optionalParameterKey].push(arg);
			}
			else{
				res['parameter'].push(arg);
			}
		}

		return res;
	}
};