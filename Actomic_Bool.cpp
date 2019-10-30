/*
Objects of std::atomic_flag must be initialized to clear
• std::atomic_flag f = ATOMIC_FLAG_INIT
• The only available operations are
• test_and_set()
• clear()

Objects of std::atomic<bool>
A more full-featured boolean flag than std::atomic_flag
std:atomic<bool> b (true);
• Operations:
• load() => bool x = b.load();
• store() => b.store(false);
• exchange() => x = b.exchange(true);

*/

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
