from sets import Set

def parse(args, flagsSet, optionalParametersSet):

	parameters = []
	optionalParameters = {}
	flags = Set([])


	optionalParameterKey = ''
	isOptionalParameter = False

	for i in range(1,len(args)):
		arg = args[i]
		if arg[0] == '-':
			isOptionalParameter = False
			if len(arg) > 1:
				if arg[1] == '-' or len(arg) == 2:
					if arg in flagsSet:
						flags.add(arg)
					else:
						optionalParameters[arg] = []
						optionalParameterKey = arg
						isOptionalParameter = True
				else:
					for j in range(1,len(arg)):
						flags.add('-'+arg[j])

		elif isOptionalParameter:
			optionalParameters[optionalParameterKey] += [arg]
		else:
			parameters += [arg]

	return parameters, optionalParameters, flags