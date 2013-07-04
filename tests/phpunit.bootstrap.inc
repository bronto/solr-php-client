<?php

// set error reporting high
error_reporting(E_ALL | E_STRICT);

// make sure we see them
ini_set('display_errors', 'On');

// make sure current directory and class directories are on include path
// this is necessary for auto load to work
set_include_path(
	// distribution files (where the zip / tgz is unpacked)
	dirname(dirname(__FILE__)) . PATH_SEPARATOR .

	// test file directory "tests"
	dirname(__FILE__) . PATH_SEPARATOR .

	// current include path (for PHPUnit, etc.)
	get_include_path()
);

spl_autoload_register(
    function($class) {
        if(strstr($class, 'PTC')) {
            include __DIR__.'/../'.str_replace('\\', '/', str_replace('PTC\\', '', $class)).'.php';
            return true;
        }
        else {
            include(str_replace("_", DIRECTORY_SEPARATOR, $class) . ".php");
        }
        return false;
    }
);
