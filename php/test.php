<?php

require_once(dirname(__FILE__).'/pinput.php');

function main($argv, $argc){
	$input = ParseInput($argv, $argc, array('--update'=>1, '--repair'=>1, '-v'=>1, '-h'=>1, '--help'=>1));
	var_dump($input);
}

main($argv, $argc);

?>