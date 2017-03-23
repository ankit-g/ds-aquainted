// polymorphism example
// if a virtual function is not a pure virtual function
// then it can be overridden, by the driver class

#include <iostream>
using namespace std;

class Enemy{
	protected:
		unsigned int AttackPower;
		Enemy(unsigned int);
	public:
		virtual void attack()
			{cout << "attack! attack! capt. attack " <<AttackPower<<endl;}
};

Enemy::Enemy(unsigned int a)
: AttackPower(a)
{

}


class Ninja: public Enemy{
	public:
		Ninja();
		void attack()
		{cout << "ninja attack! " <<AttackPower<<endl;}
};

Ninja::Ninja()
: Enemy(100)
{

}

class Monster: public Enemy{
	public:
		Monster();
};

Monster::Monster()
: Enemy(600)
{

}

int main()
{
	Ninja n;
	Monster m;
	Enemy *enemy = &n;
	enemy->attack();
	
	enemy = &m;

	enemy->attack();
}
