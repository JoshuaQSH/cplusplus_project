/*
Deadlock usually happens when at least two threads have to lock two or more mutexes in order to perform an operation. 
Use mutex to solve deadlock issue
Use lock_guard() instead of std::lock()

G #1: Avoid nested locks
• If you really must seize multiple locks, use
std::lock()
• G #2: Avoid calling user-supplied code while holding a lock
• That code could also acquire locks – hard to track.
• G #3: Acquire locks in a fixed order
• Need a way that is consistent between threads
• May need, e.g., to define a “canonical order of traversal”
for data structures
• G #4: Use a lock hierarchy

*/

#include <exception>
#include <memory>

struct empty_stack: std::exception
{
  const char* what() const throw();
};
