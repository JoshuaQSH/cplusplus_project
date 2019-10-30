#include <vector>
#include <atomic>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

std::vector<int> data;
std::atomic<bool> ready(false);

void reader_thread()
{
    while (!ready.load())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    std::cout << "Answer is " << data[0] << "\n";
}

void writer_thread()
{
    data.push_back(42);
    ready = true;
}

int main()
{
    // writer_thread();
    reader_thread();
    writer_thread(); // It will pause here and output nothing since reader_thread ready.load() will always be false
    
    return 0;
}
