/*
 *	I'm so gonna Kill you right now.
 *	Wohhahaahha !!! RUN RUN RUN
 * */

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
using namespace std;


/*
 *	Wohahahahahah !!!!
 * 
 *
 *	The MaliciousBehavior class has 6 functions
 *	Each function is an elaborate plan to drown yor ass.
 *	this has following commands to do this shit okay.
 *	im_gonna_attack_you is the point where this prgm prepares to attack youer bitch
 *	my_attack_stratigy is where it tries to use one of his attack statigy.
 *	my_attak_methods one of the move, immidiate move
 *
 */

class MaliciousBehavior
{
private:
	virtual void im_gonna_attack_you(void)=0;
	virtual void my_attack_stratigy(void)=0;
	virtual void my_attak_methods(void)=0;
	virtual void my_result_after_the_move(void)=0;
	virtual void the_areas_m_attacking(void)=0;
	virtual void the_xxx_and_the_xxx_i_use(void)=0;

public: // No body should ever fucking touch this implementation
	// This should never change okay;
	virtual void fuck_the_system(void)
	{
		this->im_gonna_attack_you();
		this->my_attack_stratigy();
		this->my_attak_methods();
		this->my_result_after_the_move();
		this->the_areas_m_attacking();
		this->the_xxx_and_the_xxx_i_use();
	};
};
