#include "stl_all.h"

typedef Pair<string, Pair<int, int> > PAIR;

struct PairOpr : public CntOperations 
{
public:
	static bool cmp_data(const PAIR &a, const PAIR &b)
	{
		return (a.second.first < b.second.first);
	}
};

template <typename T>
class StlVec: public MyContainer {
public:
	void add_newdata()
	{
		T *data = (T *)cops->add_to_cntr();

		vec.push_back(*data);

		delete data;
	}

	void print_all_data()
	{
		if (true == vec.empty())
		return;

		const int size = vec.size();
		int itr;
		
		for (itr=0; itr < size; itr++) {
			cops->print_data((void *)&vec.at(itr));
		}
	}

	void sort_all_data()
	{
		stable_sort(vec.begin(), vec.end(), PairOpr::cmp_data);
	}

	
	StlVec(CntOperations *ops)
	: MyContainer(ops) {}
private:
	vector<T> vec;
};

string noun[] = {"building", "chair", "master", "bottle", "cream", 
		"fan", "window", "mirror", "table", "teacher"};

string adj[] = {"mad", "sad", "happy", "angry", "funny",
		"crazy", "walking", "playing", "studying", "boring"};
	

void print_sentence(void *vec_obj)
{
	PAIR *pr = (PAIR*)vec_obj;

	cout << pr->first << " " <<
	pr->second.first << " "<< 
	pr->second.second << endl;
}

void *add_to_sentence_vector(void)
{
	PAIR *pr = new PAIR();

	int rnd_noun = rand()%10;
	int rnd_adj  = rand()%10;
	
	pr->first = noun[rnd_noun] + " is " + adj[rnd_adj];
	pr->second.first = rnd_noun;
	pr->second.second = rnd_adj;

	return (void *)pr;
}

int vector_trail(void)
{	
	PairOpr ops;
	
	ops.add_to_cntr = add_to_sentence_vector;
	ops.print_data = print_sentence;

	StlVec<PAIR> sen_vec(&ops);
	MyContainer *Con = &sen_vec;

	for (int i = 0; i < 20; i++)		
	Con->add_newdata();
	Con->print_all_data();	
	sen_vec.sort_all_data();

	cout << endl;
	
	Con->print_all_data();
}

int main(void)
{
	map<int, int> my_map;

	my_map[-2000000] = 1;

	if(my_map.find(10) == my_map.end())
		my_map[10] = 1;

	map<int, int>::iterator it;

	for (it = my_map.begin(); it != my_map.end(); it++)
		cout << it->first << " : " << it->second << endl;
	
	my_map[10] += 1;	
	
	for (it = my_map.begin(); it != my_map.end(); it++)
		cout << it->first << " : " << it->second << endl;

	cout << my_map.at(10) << endl;
	
	return EXIT_SUCCESS;
}
