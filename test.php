<?php

function test()
{
	$result = TestExtension::serialize(0);
	$r = $result[0];
	var_dump($r);
}

test();

