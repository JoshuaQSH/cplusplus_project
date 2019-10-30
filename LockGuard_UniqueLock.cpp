/*
lock_guard owns its mutex
• sometimes too inflexible: want to pass mutex around

std::unique_lock
• doesn’t always own the mutex associated with it
• can be created with defer_lock on its mutex
• implements lock(), unlock() and try_lock()
• ownership can be queried with owns_lock()
• when a unique_lock object is destroyed ..
• mutex unlocked if and only if it is owned by the object
• supports moving ownership outside of scopes, or early
release of mutex if not required on particular code
pathways

• share_ptr
Accept a requested memory address, 
construct a smart pointer object to be stored on the stack, 
and when the program exits the scope of the stack, 
the stored memory inside the smart pointer is freed (unless the smart pointer is saved) 

*/

#include <list>
#include <mutex>
#include <algorithm>
#include <memory> // For share_ptr

std::list<int> some_list;    // A global variable that is protected by a global mutex
std::mutex some_mutex;       // Create that can protect the variable above

std::shared_ptr<some_resource> resource_ptr; //share_ptr is a Smart Pointer
std::mutex resource_mutex;

void add_to_list(int new_value)
{
  std::lock_guard<std::mutex> guard(some_mutex); // guard is the name of the std::lock_guard<std::mutex> 'some_mutex' is the variable that needs to be protectd
  some_list.push_back(new_value);
}

bool list_contains(int value_to_find)
{
  std::lock_guard<std::mutex> guard(some_mutex);    // 4
  return std::find(some_list.begin(),some_list.end(),value_to_find) != some_list.end();
}

void foo()
{
  std::unique_lock<std::mutex> lk(resource_mutex);  // All the thread should be initialize here
  if(!resource_ptr)
  {
    resource_ptr.reset(new some_resource);  // Only when initializing, the protection is required 
  }
  lk.unlock();  // Unlock the 'resource_mutex'
  resource_ptr->do_something();
}

