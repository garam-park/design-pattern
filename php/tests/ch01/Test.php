<?php
use PHPUnit\Framework\TestCase;

use G\Chapter01\Character;
use G\Chapter01\Knife;
use G\Chapter01\Sword;

class Test extends TestCase
{
    public function testTest()
    {
    	$c = new Character(new Knife);
    	$this->assertEquals('attack with KNIFE!!',$c->attack());

    	$c->setWeapon(new Sword);
    	$this->assertEquals('attack with Sword!!',$c->attack());
    }
}
?>