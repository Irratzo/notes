using namespace std;

#include <iostream>
#include <stdlib.h>
#include <vector>

void sortierenDurchAufsteigen (int liste[], int length) {
  int n = length;
  bool sorted;

  do {
    sorted = false;
    for (int i=0;i<n-1;i++) {
      if (liste[i] > liste[i+1]) {

	swap(liste[i],liste[i+1]);

	//doesnt work, should use extra variable for temporary storage
	// liste[n]=liste[i];
	// liste[i]=liste[i+1];
	// liste[i+1]=liste[n];

	sorted = true;
	
      }
    }
    n--;
  }while(sorted && (n>1));

}


int main (int argc, char** argv) {

  int length = argc-1;
  int * liste = new int[length];


  for (int i=0; i<length; i++) {
    liste[i] = atoi(argv[i+1]);
  }


  sortierenDurchAufsteigen(liste,length);


  for (int i=0; i<length; i++) {
    cout << liste[i] << ' ';
  }

  cout << endl;

  return 0;
}

