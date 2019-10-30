/*
Using std::thread to create thread to transfer variances.
Using thread.join() to join the threads.
Note that the default is to transfer the parameters in the copy way to the thread space, even if the type of the parameters are reference.
*/

#include <iostream>
#include <thread>

using namespace std;

class X
{
    public:
    void do_sth()
    {
        cout << "Hello World" << endl;
    }
};

void func(int a,int b){
    cout << "a = " << a << ", b = " << b << endl;
}

int main()
{
    X my_x;
    thread t(&X::do_sth,&my_x);
    std::thread t1(std::bind(func, 1, 2));
    std::thread t2([](int a, int b){cout << "a = " << a << ", b = " << b << endl;}, 1,2);
    std::thread t3(func,1,2);
    
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
