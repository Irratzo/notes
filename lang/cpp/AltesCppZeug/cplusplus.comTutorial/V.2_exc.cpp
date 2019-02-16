#include <iostream>
#include <exception>
using namespace std;

/*
int main () {
try
{
  int * myarray= new int[10000000000];
}
catch (bad_alloc&)
{
  cout << "Error allocating memory." << endl;
}
 return 0;
}
*/

int main () {
  try
  {
    int* myarray= new int[1000000000000];
  }
  catch (exception& e)
  {
    cout << "Standard exception: " << e.what() << endl;
  }
  return 0;
}

