#include <iostream>
#include<initializer_list>
#include<memory>
#include<fstream>
#include <sstream>
#include<cassert>
#include<chrono>
#include<cmath>
#include "MovetoFront.h"
#include "O_List.h"
using namespace std;
int main(int argc, const char * argv[])
{
  MovetoFront lis1;
  std::ifstream file;
  file.open(argv[1]);
  int len;
  file >> len; //reads the number of items to int len
  O_List o1(len); //establishes size of ordered list object
 for(int i = 0; i < len; i++)
  {
    int x;
    file >> x;
    lis1.ADD(x);
  }
  int queryNum;
  file >> queryNum;
  int traversal = 0;
  auto start = std::chrono::steady_clock::now();
  for (int i = 0; i < queryNum; i++)
  {
    
    int queries;
    file >> queries; 
    traversal += lis1.query(queries);
   // count += o1.Search(queries);
    
  }
  file.close();
  auto end = std::chrono::steady_clock::now();
  std::cout<<"MTF List After Queries: ";
  lis1.PRINT();
  std::cout<<"\nMTF Traversal Count: "<<traversal<<"\n";
   std::chrono::duration<double> elapsed_seconds = end-start;
   std::cout << "MTFList Time: " << elapsed_seconds.count()*pow(10,9) << " nanoseconds\n";
  /* Reading again for the Ordered List*/ 
  std::ifstream file2;
  file2.open(argv[1]);
  int file2_length;
  file2 >> file2_length;
  O_List o2(file2_length);
  for(int i = 0; i < file2_length; i++)
  {
    int y;
    file2 >> y;
    o2.ADD(y);
  }
  int count = 0;
  int BinsearchNum;
  file2 >> BinsearchNum;

  auto windward = std::chrono::steady_clock::now();
  for (int i = 0; i < BinsearchNum; i++)
  {
    
    int searches;
    file2 >> searches; 
    count += o2.Search(searches);
    
  }
  auto leeward = std::chrono::steady_clock::now();
  std::cout<<"Ordered List After Queries: ";
  o2.PRINT();
  std::cout<<"\nOrdered List Traversal Count:"<< count<<"\n";
  std::chrono::duration<double> time_elapsed = leeward-windward;
  std::cout << "Ordered List Time: " << time_elapsed.count()*pow(10,9) << " nanoseconds\n";
  if (time_elapsed > elapsed_seconds)
  {
    std::cout <<"MTF is faster for this data";
  }
  else if (time_elapsed < elapsed_seconds)
  {
    std::cout <<"Ordered List is faster for this data";
  }
  return 0;
}