<?php

namespace G\Chapter01;

use G\Chapter01\Weapon;
use G\Chapter01\Knife;
/**
* 
*/
class Character
{
	private $weapon;

	function __construct(Weapon $weapon)
	{
		$this->weapon = $weapon;
	}

	public function setWeapon(Weapon $weapon)
	{
		$this->weapon = $weapon;
	}

	public function attack()
	{
		return $this->weapon->attack();
	}
}

$c = new Character(new Knife);
$c->attack();