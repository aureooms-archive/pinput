<?php

function ParseInput($argv, $argc, $flags){
	$res = array();
	$res['parameter'] = array();
	$res['optional'] = array();
	$res['flag'] = array();


	$optionalParameterKey = '';
	$isOptionalParameter = false;

	for($i = 1; $i < $argc; ++$i){
		$arg = $argv[$i];
		if($arg[0] == '-'){
			$isOptionalParameter = false;
			if(strlen($arg) > 1){
				if($arg[1] == '-' || strlen($arg) == 2){
					if(isset($flags[$arg])){
						$res['flag'][$arg] = 1;
					}
					else{
						$res['optional'][$arg] = array();
						$optionalParameterKey = $arg;
						$isOptionalParameter = true;
					}
				}
				else{
					for($j = 1; $j < strlen($arg); ++$j){
						$res['flag']['-'.$arg[$j]] = 1;
					}
				}
			}
		}
		else if($isOptionalParameter){
			array_push($res['optional'][$optionalParameterKey],$arg);
		}
		else{
			array_push($res['parameter'],$arg);
		}
	}

	return $res;
}
?>