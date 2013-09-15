import java.util.List;
import java.util.Map;
import java.util.Set;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

class Test {
	public static void main (String[] args){
		List<String> params = new ArrayList<String>();
		Map<String,ArrayList<String>> options = new HashMap<String,ArrayList<String>>();
		Set<String> flags = new HashSet<String>();
		Set<String> flagSet = new HashSet<String>();
		flagSet.add("-h");
		flagSet.add("--help");
		flagSet.add("-v");
		Pinput.parse(args, params, options, flags, flagSet);
		System.out.println(params);
		System.out.println(options);
		System.out.println(flags);
	}
}