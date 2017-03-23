// Pure Virtual functions must be overridden
// This now describes an abstract class
// An abstract class is a class with pure virtual function
// There can be no instance of an abstract class

#include <iostream>
using namespace std;

class Enemy{	
	public:
		Enemy(int);
		Enemy();
		unsigned int poop;
		virtual void attack()=0;
		void oh_poop (void)
		{cout << "oh!! POOP !! " << poop << endl;}
};

Enemy::Enemy()
: poop(0xcafebabe)
{}

Enemy::Enemy(int a)
:poop(a)
{}

class Ninja: public Enemy{
	public:
		Ninja();
		void attack()
		{cout << "ninja attack!" <<endl;}
};

Ninja::Ninja()
:Enemy(400)
{}

class Monster: public Enemy{
	public:
		void attack()
		{cout << "monster attack!" << endl;}
};

int main()
{
	Ninja n;
	Monster m;
	Enemy *enemy1 = &n;
	Enemy *enemy2 = &m;
	enemy1->attack();
	enemy2->attack();

	enemy1->oh_poop();
	enemy2->oh_poop();
}
