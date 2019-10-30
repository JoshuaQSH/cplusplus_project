/*
Deadlock usually happens when at least two threads have to lock two or more mutexes in order to perform an operation. 
Use mutex to solve deadlock issue
Use lock_guard() instead of std::lock()

*/

#include <exception>
#include <memory>

struct empty_stack: std::exception
{
  const char* what() const throw();
};
