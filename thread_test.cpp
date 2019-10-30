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

int main()
{
    X my_x;
    thread t(&X::do_sth,&my_x);
    t.join();

    return 0;
}
