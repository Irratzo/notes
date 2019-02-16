// Sieb des Eratosthenes zur Filterung der Primzahlen zwischen 1 und n

#include <iostream>

int main()
{
	int n;
	
	// Einlesen des Wertes bis zu dem die Primzahlen gesucht werden sollen
	std::cout << "max: ";
	std::cin >> n;

	// Deklaration eines dynamischen Arrays für die Zahlen
	// a[i] == true heisst, die Zahl wurde gefiltert
	bool * a = new bool[n];
	for(int i=0;i<n;a[i]=false,i++);

	// einfache Implementierung des Siebs mit zwei geschachtelten for-Loops
//	for(int i=2; i<n; ++i) {
//		if(!a[i]) {
//			for (int j=i+1; j<n; ++j) {
//				if(j%i == 0) a[j] = true;
//			}
//		}
//   }

	// dieser for-Loop macht das Gleiche wie die beiden geschachtelten
	for(int i=2, j=0; i&&(j||a[i]||(j=i+1)); (j&&(++j%=n))||(++i%=n))
		(j%i)||(a[j]=1);

	// Ausgabe der Primzahlen zwischen 1 und n
	for(int i=2; i<n; ++i) {
		if(!a[i]) std::cout << i << std::endl;
	}
	
	// Speicher freigeben
	delete [] a;
	
	// Programm erfolgreich beendet
	return 0;
}
