#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>

#define RAND_ARRAY_SIZE 10000000
#define CHECK_ARRAY_SIZE 100000000

using namespace std;
extern void start_timer(void);
extern void end_timer(void);
/* test array */
int arr[] = {9,6,1,1,1,0,0,7,2,3};
unsigned int rand_arr[RAND_ARRAY_SIZE];
unsigned int check_arr[CHECK_ARRAY_SIZE];

bool comp_ints (int a , int b)
{
    return(a<b);
}

void init_rand_array(void)
{
    cout << "init start" << endl;
    start_timer();
    for (int index = 0; index < RAND_ARRAY_SIZE; index++)
    {
        int rnum_found = 0;
        int rand_num;
        while (0 == rnum_found) 
        {
            rand_num = rand()%CHECK_ARRAY_SIZE;

            if (0 == check_arr[rand_num]) {
                check_arr[rand_num] = 1;
                rnum_found = 1;
            }
        }

        rand_arr[index]  = rand_num;
    }
    end_timer();
    cout << "init end" << endl;
}

#define FOUND 1
#define NOT_FOUND -1

int find_element(const int ele, int start, int end, vector<int> &vect)
{
    if (start > end)
    return NOT_FOUND;

    int diff = (end - start)/2;
    int middle = start + diff;

    if (ele == vect[middle])
        return FOUND;
    else if (ele > vect[middle])
        return find_element(ele, middle + 1, end, vect);
    else if (ele < vect[middle])
        return find_element(ele, start, middle - 1, vect);
}

bool check_for_on_disk_array(void)
{
    int fd;
    int val = 0;

    fd = open("array_check", O_RDONLY|O_CREAT, 0666);
    if (fd < 0) {
        perror("open");
        exit(0);
    }

    if (read(fd, &val, sizeof(val)) < 0) {
        perror("read");
       // exit(0); 
    }

    close(fd);
    if (1 == val)
        return true;
    else
        return false;

}

void load_from_disk(void)
{   
    int fd;

    fd = open("random_array", O_RDWR|O_CREAT);
    if (fd < 0) {
        perror("open");
        exit(0);
    }

    if (read(fd, &rand_arr, sizeof(rand_arr)) < 0) {
        perror("read");
        exit(0); 
    }

    close(fd);
}

void store_array_on_disk(void)
{
    int fd_verify;
    int fd_store;
    int val = 1;

    fd_verify = open("array_check", O_RDWR);
    if (fd_verify < 0) {
        perror("array_check open");
        exit(0);
    }

    fd_store = open("random_array", O_RDWR|O_CREAT, 0666);
    if (fd_store < 0) {
        perror("random_array open");
        exit(0);
    }

    if (write(fd_store, rand_arr, sizeof(rand_arr))<0) {
        perror("write");
        exit(0);
    }    
    
    if (write(fd_verify, &val, sizeof(val))<0) {
        perror("write");
        exit(0);
    }

    close(fd_verify);
    close(fd_store);
}

#define NAMELEN 16
#define TESTLEN 100
struct test_val
{
    char name[NAMELEN];
    int index;
};

bool comp_struct (struct test_val a , struct test_val b)
{
    return(a.index < b.index);
}

void sort_struct_vector(void)
{
    vector<struct test_val> test_vec;

    for (int i = 0; i < TESTLEN; i++) {
        struct test_val test;
        test.index = rand_arr[i];

        test_vec.push_back(test);
    } 
    
    stable_sort(test_vec.begin(), test_vec.end(), comp_struct);
    
    for (int i = 0; i < TESTLEN; i+=4) {
        cout << " test " << i << " "
            << test_vec[i].index << " " << endl;
        cout << " test " << i+1 << " "
            << test_vec[i+1].index << " " << endl;
        cout << " test " << i+2 << " "
            << test_vec[i+2].index << " " << endl;
        cout << " test " << i+3 << " "
            << test_vec[i+3].index << " " << endl;
    }
}

int main(void)
{
    bool array_is_on_disk;
   /********** STAGE I ********************/
    vector<int> Vect;


    // check if the rand array is present on disk
    if (false == check_for_on_disk_array()) {
        init_rand_array();
        store_array_on_disk();    
    } else {
        cout << "load array from disk ";
        load_from_disk();
        cout << "done" << endl;
    }

    sort_struct_vector();
    return 0;
    start_timer();
    printf("push 10 Million elements\n"); 
    for (int i = 0; i < RAND_ARRAY_SIZE; i++) {
        Vect.push_back(rand_arr[i]);
    }
    
    printf("stable sort 10 Million elements\n");
    stable_sort(Vect.begin(), Vect.end(), comp_ints);
    end_timer();

    start_timer(); 
    printf("find 1 million elements in that vector\n");
    for (int crawler = 0; crawler < 1000000; crawler++) {
        find_element(rand()%CHECK_ARRAY_SIZE, 0, Vect.size(), Vect);
    }
    end_timer();

    cout << endl;
    return 0;
}
