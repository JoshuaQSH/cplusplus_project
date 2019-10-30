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

*/

#include <list>
#include <mutex>
#include <algorithm>

std::list<int> some_list;    // A global variable that is protected by a global mutex
std::mutex some_mutex;       // Create that can protect the variable above

void add_to_list(int new_value)
{
  std::lock_guard<std::mutex> guard(some_mutex);    // 3
  some_list.push_back(new_value);
}

bool list_contains(int value_to_find)
{
  std::lock_guard<std::mutex> guard(some_mutex);    // 4
  return std::find(some_list.begin(),some_list.end(),value_to_find) != some_list.end();
}
