#include "stl_all.h"

template <typename T>
class StlVec: public MyContainer {
public:
	void add_newdata()
	{
		T *data = (T *)cops.add_to_cntr();

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
			cops.print_data((void *)&vec.at(itr));
		}
	}
	
	StlVec(CntOperations ops)
	: MyContainer(ops) {}
private:
	vector<T> vec;
};

typedef Pair<string, Pair<int, int> > PAIR;
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

int main(void)
{
	CntOperations ops;
	
	ops.add_to_cntr = add_to_sentence_vector;
	ops.print_data = print_sentence;

	StlVec<PAIR> sen_vec(ops);
	MyContainer *Con = &sen_vec;

	for (int i = 0; i < 20; i++)		
	Con->add_newdata();
	Con->print_all_data();	
	return EXIT_SUCCESS;
}
