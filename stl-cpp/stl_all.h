#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
/*
 * Special data type for much more complicated initializatons.
 */

template <class J, class K>
struct Pair
{
	J first;
	K second;
};

struct CntOperations
{
	void (*print_data)(void *);
	void *(*add_to_cntr)(void);
	virtual bool cmp_data(){};
};

class MyContainer
{
public:
	virtual void add_newdata()=0;
	virtual void print_all_data()=0;
	MyContainer (CntOperations *ops)
	: cops(ops) {}
protected:
	struct CntOperations *cops;
};
