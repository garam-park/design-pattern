## **전략 패턴**

### **전략 패턴 요약 설명**

+ **타입** : `행위`
+ **설명** : 클라이언트 객체에서 서로 교환 가능한 다른 구현들을 의존성없이 변경 가능하도록 하는 패턴

### **인터페이스**

인터페이스는 객체지향언어에서 추상화의 개념을 잘 사용하도록 최적화 되어있습니다. 유연한 프로그램은 객체간의 의존성을 줄이기 위해서 인터페이스를 사용하며 서로 대화를 나눌 때에 인터페이스를 사용합니다.

인터페이스는 기본적으로 객체에 대한 **선언과 구현을 분리**하는 기능을 가지고 있습니다. 

```java
//기능에 대한 선언
interface AInterface {
	void functionA();
}
```

인터페이스는 기본적으로 구현을 해야하는 것에 대한 선언을 해줍니다. 선언이라는 것을 '어떤 것을 하겠다'는 의사표현이기도 하고 '기능을 이렇게 사용하자'라는 약속이 될 수도 있습니다.

인터페이스는 객체간의 의사소통을 도와주는 **통로**의 역할을 합니다. 

```java
//선언 후 구체적인 구현이 어떤지 클래스를 통해서 만들 수 있다.
class AImplements implements AInterface {
	public void functionA(){
		//구현
	}
}

//...

public static void main(String[] args) {
	
	AInterface aInterface = new AImplements();

	// aInterface가 어떻게 동작 할지는 런타임에서 결정된다.
	aInterface.functionA();
}

```

위의 코드를 보면 `aInterface`는 `AImplements`라는 구현체를 레퍼런스하게 됩니다. 인터페이스는 프로그램에서 구현체와 다른 객체들간에 소통을 도와주는 다리 역할을 합니다.

### **델리게이트**

`위임하다`라는 뜻입니다. 델리게이트 객체지향언어의 주요 개념입니다. 인터페이스의  두 객체가 있다고 하면 위임하는 객체가 있고 위임 받는 객체가 있습니다. 델리게이트는 인터페이스가 어떻게 서로 소통하는지 보여주는 가장 간단한 방법입니다. 다음의 자바 예제를 살펴 보도록 하겠습니다.

```java
class A {
	void functionA() {
		B b = new B();
		b.functionB();
	}
}

class B {
	void functionB() { /*구현*/}
}
```

예제를 보면 A 클래스의 functionA 의 기능을 동작하는 방법은 B 클래스의 인스턴스를 만들고 B 클래스의 인스턴스의 functionB 를 호출합니다. 다시 말하면 기능 functionA 를 B에게 `위임`하는 것입니다. A 클래스는 사실상 구현한 것이 없고 B 클래스의 구현을 동작을 하는 것입니다. 이것이 바로 위임, 델리게이트의 개념입니다.

### **전략 패턴**

전략 패턴은 객체지향언어에서 두드러지는 특징은 추상화를 가장 간단하게 보여주는 좋은 패턴입니다. 전략 패턴을 이해하면 `DI:Dependency Injection` 이나 `IoC:Inversion of Controll` 를 이해하는데에 도움이 됩니다.

전략 패턴은 동일한 기능에 대한 선언을 가진 인터페이스를 다양한 클래스로 구현하고 각각의 구현들을 변경하면서 사용할 수 있도록 하는 패턴입니다.

#### **UML**

![](https://user-images.githubusercontent.com/7725665/30330328-c4410f50-980f-11e7-95d4-79b111c4a2ed.png)

#### **예제**

Java 예제

```java
//Main.java
public class Main {

	public static void main(String[] args) {
		
		GameCharacter character = new GameCharacter();
		
		character.setWeapon(new Sword());
		character.attact();
		
		character.setWeapon(new Ax());
		character.attact();
		
		character.setWeapon(new Knife());
		character.attact();
	}
	
}

//GameCharacter.java
public class GameCharacter {

	private Weapon weapon;

	public int attact() {
		return weapon.doAttact();
	}

	public void setWeapon(Weapon weapon) {
		this.weapon = weapon;
	}

}

//Weapon.java
public interface Weapon {
	public int doAttact();
}


//Sword.java
public class Sword implements Weapon {
	public int doAttact() {
		System.out.println("검 공격");
		return 0;
	}

}

//Knife.java
public class Knife implements Weapon {

	public int doAttact() {
		System.out.println("칼 공격");
		return 0;
	}

}

```

PHP 예제

```php
interface Weapon
{
	function attack();
} // END interface Weapon

class Sword implements Weapon
{	
	function attack()
	{
		return 'attack with Sword!!';
	}
}

class Knife implements Weapon
{	
	function attack()
	{
		return 'attack with KNIFE!!';
	}
}

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

$c = new Character(new Sword);
$c->attack();//attack with Sword!!
$c->setWeapon(new Knife);
$c->attack();//attack with KNIFE!!

```


C++ 예제

```cpp
#include <iostream>

using namespace std;

class Weapon   
{   
public:
	virtual void doAttack() = 0;
};

class Character
{
protected:
	Weapon * w;
	
public:
	Character(Weapon *w);
	void doAttack();
	Character * setWeapon(Weapon *w);
};

Character::Character(Weapon * w){
	this->w = w;
}

Character * Character::setWeapon(Weapon * w){
	this->w = w;
	return this;
}

void Character::doAttack(){
	w->doAttack();
}

class Sword : public Weapon
{
protected:
	
public:
	void doAttack();
};

void Sword::doAttack(){
	cout << "Sword Attack!!" << endl;
}

class Knife : public Weapon
{
protected:
	
public:
	void doAttack();
};

void Knife::doAttack(){
	cout << "Knife Attack!!" << endl;
}

int main() {
	Character * c = new Character(new Sword());
	c->doAttack();
	c->setWeapon(new Knife());
	c->doAttack();
   return 0;
}
```

Python 예제

```python
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
```

C# 예제

```cs
///준비중
```
