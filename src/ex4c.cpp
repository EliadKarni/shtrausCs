/*
file: ex4c.cpp

The goal of this program is to create (initialize) dynamic array, sort it, print it 
and add new elements to it.

The array can be of any type. Specific in this exercise, Date or Time.

*/
#include "ex4c_given.h"

void my_exit(int line, const char* msg)
{
  cerr << "internal error in line " << line 
       << " ; " << msg << endl;
  exit(1);
}

// ***  Generic functions and types  ***
typedef bool  (*read_item)  (void*);
typedef void  (*print_item) (void*);
typedef int   (*comp_items) (const void*, const void*);
typedef void  (*swap_items) (void*, void*);
typedef void  (*copy_item)  (void*, const void*); // first arg is destination
typedef void* (*alloc_arr)  (int size);
typedef void* (*alloc_item) ();
typedef void  (*delete_arr) (void*&);
typedef void  (*delete_item)(void*&);
typedef void* (*item_at)    (void* ptr, int index);


//*** Struct declarations ***

// structure to hold generic functions
struct Functions{
  read_item   _read_item;
  print_item  _print_item;
  comp_items  _comp_item;
  swap_items  _swap_item;
  copy_item   _copy_item;
  alloc_arr   _alloc_arr;
  // a few more members are needed
  
};


/*===================================================
==  Date functions and Date Wrap Functions        ==*  
===================================================*/
/*
  You have to define here functions like:
  read_date
  print_date
  comp_date
  alloc_date_arr
  * and a few more *  
  * hint: corresponding to the typedef's above *
*/
bool read_date(void* ptr) {
    return read_date((Date*)ptr);
}




/*===================================================
==  Time functions and Time Wrap Functions        ==*  
===================================================*/
/*
  You have to define here functions like above,
  but here - for handling Time
*/

/*===================================================
==         ex4c generic functions                 ==*  
===================================================*/

//  ****  global variables ***
const Functions DATE_FUNCS = {  
  read_date,
  print_date, 
  comp_date,
  swap_date,
  copy_date,
  alloc_date_arr,
  alloc_date_item,
  // add code here

 };

const Functions TIME_FUNCS = {  
  read_time, 
  print_time, 
  comp_time,
  swap_time,
  copy_time,
  alloc_time_arr,
  alloc_time_item,
  // add code here

 };

//==================================================
/* recommended functions which are needed here:
  resize_arr
  init_arr
  print_arr  ** Note the function is partially implemented below  **
  sort_arr
  add_item
*/

//==================================================
void print_arr(const Arr_Struct& arr, const Functions* functions)
{
  cout << "Size = " << arr._size 
       << " Capacity = " << arr._capacity << endl;
  for (int j=0 ; j < arr._size; j++)
  {
    // add code to print one item of the array
    
    cout << endl;
  }
}

//==================================================
int main(int argc, char** argv)
{ 
  const Functions* func_ptr = nullptr;
  
  Type type = select_type();
    
  switch (type)
  {
  case Date:
      func_ptr = &DATE_FUNCS;
    // add missing code

    default: my_exit(__LINE__, "bad Type");
  };
  func_ptr->_read_item(nullptr);
  while(true)
  {
    Action act = select_action();  
     
    switch (act)
    {
      case INIT:  init_arr(/* list of args */);
                  break;
      case PRINT: print_arr(/* list of args */);
                  break;
      case SORT:  sort_arr(/* list of args */);
                  break;
      case ADD:   add_item(/* list of args */);
                  break;
      case EXIT:  exit(0);
      default: my_exit(__LINE__, "bad action code");
    }
  }
}
