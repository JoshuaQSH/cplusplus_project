/*
Implementation of multi-threads
*/

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void test(int& i)
{
  i++;
  cout << "Test " << i << endl;
}

int main()
{
    int sum = 0;
    std::vector<std::thread> ts; // Put threads into a vector
    for(int i=0;i<8;i++)
    {
        ts.push_back(std::thread(test,std::ref(sum))); // std::ref means passing the variable in a reference way
    }
    
    for(auto& t:ts)
        t.join();
        
    
    cout << "End! The final sum is " << sum << endl; 
    return 0;
}
