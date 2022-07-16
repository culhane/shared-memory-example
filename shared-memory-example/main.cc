#include <iostream>

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

using namespace boost::interprocess;

int main()
{
  shared_memory_object shm(create_only, "shared_memory3", read_write);
  uint64_t shared_memory_size = 1048576; // 1MB
  shm.truncate(shared_memory_size); // resize 

  mapped_region region(shm, read_write);

  void* cb_ptr = region.get_address();
}