/*
Using std::thread to create thread to transfer variances.
Using thread.join() to join the threads.
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
