#include <memory>
#include <iostream>
#include "O_List.h"
O_List::O_List(){
    size = 0;
    end = 0;
   ptr = new int[size];
}
O_List::O_List(int length)
{
   size = length;
   end = 0;
   ptr = new int[size];

   for ( int i = 0; i < size; i++ )
   {
      ptr[i] = 0;
   }
}

O_List::~O_List()
{
    delete[] ptr;
    size = 0;
}

void O_List::ADD(int num)
{
    ptr[end] = num;
    end++;
}

void O_List::PRINT()
{
    for(int i = 0; i < (size); i++)
    {
        std::cout<< " "<<ptr[i];
    }
}
  /*
    Procedure binary_search
   A ← sorted array
   n ← size of array
   x ← value to be searched

   Set lowerBound = 1
   Set upperBound = n 

   while x not found
      if upperBound < lowerBound 
         EXIT: x does not exists.
   
      set midPoint = lowerBound + ( upperBound - lowerBound ) / 2
      
      if A[midPoint] < x
         set lowerBound = midPoint + 1
         
      if A[midPoint] > x
         set upperBound = midPoint - 1 

      if A[midPoint] = x 
         EXIT: x found at location midPoint
   end while
   
end procedure
  */
int O_List::Search(int num)
{
    //num = value to be searched
    int count = 0; //returned traversal after each search
    end = 0;
    int l = ptr[end];//lower bounds
    int n = ptr[size-1]; //upper bounds
    while( num != true)//while num is not found 
    {
        count++;
        if(n < l)
        {
            std::cout<<num<<" not in list";
            return 0;
        }

        int midpoint = l + (n-l) / 2; //sets midpoint
        
        if(ptr[midpoint] < num ) 
        {
            l = midpoint + 1;
            count++;
            //return count;
        }

        if(ptr[midpoint] > num)
        {
            n = midpoint - 1;
            count ++;
            //return count;
        }
        if(ptr[midpoint] == num)
        {
            return count;
        }
    }
}

