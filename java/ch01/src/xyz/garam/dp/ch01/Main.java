package xyz.garam.dp.ch01;

public class Main {

	public static void main(String[] args) {
		
		GameCharacter character = new GameCharacter();
		
		character.setWeapon(new Sword());
		character.attact();
		
		// character.setWeapon(new Ax());
		// character.attact();
		
		character.setWeapon(new Knife());
		character.attact();
	}
	
}