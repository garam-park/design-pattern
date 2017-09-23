import abc 

class Weapon:

	__metaclass__ = abc.ABCMeta

	@abc.abstractmethod
	def doAttack(self):
		pass

class Knife(Weapon):
	def doAttack(self):
		print("Attack Knife!!")


class Sword(Weapon):
	def doAttack(self):
		print("Attack Sword!!")

class Character:
	def __init__(self, weapon):
		super(Character, self).__init__()
		self.weapon = weapon
	def setWeapon(self,weapon):
		self.weapon = weapon
	def doAttack(self):
		self.weapon.doAttack()

c = Character(Knife())
c.doAttack()
c.setWeapon(Sword())
c.doAttack()