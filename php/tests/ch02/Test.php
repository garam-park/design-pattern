<?php
use PHPUnit\Framework\TestCase;

use G\Chapter02\SgCalculator;

class Test extends TestCase
{
    public function testTest()
    {
    	$c = new SgCalculator;

    	$r = $c->double(3);

    	$this->assertEquals(6,$r);
    }
}
?>