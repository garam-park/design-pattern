package xyz.garam.dp.ch01;

public class GameCharacter {

	private Weapon weapon;

	public int attact() {
		return weapon.doAttact();
	}

	public void setWeapon(Weapon weapon) {
		this.weapon = weapon;
	}

}
