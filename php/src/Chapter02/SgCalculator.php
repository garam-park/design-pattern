<?php

namespace G\Chapter02;

use G\Chapter02\Calculator;
use G\Chapter02\Library\Shift;

/**
* 
*/
class SgCalculator implements Calculator
{

	function __construct()
	{
		$this->shift = new Shift;
	}

	public function double($number)
	{
		return $this->shift->left($number,1);
	}
}