#include "LetterFrequency.h"

using namespace std;

//int symbolSet[] = {'A','B','C','D'};
//int symbolFreqOrig[]  = {3,6,9,0,0,4,0,0,9,0,0};
int no_of_symbols;
unsigned short int *symbolFreq;
std::map<int, int> LetterMap;
vector<char> symbolList;
//

void setLetterFrequency(char *memblock) {

	//Declare the symbolFreq
	no_of_symbols = 256;
//	symbolList = new int[no_of_symbols];
	symbolFreq = new unsigned short int[no_of_symbols];
	//Initialize the symbolFreq
	for (int i = 0; i < no_of_symbols; i++) {
		symbolFreq[i] = 0;
	}
	//Store the file in Hashmap
//	  std::map<char,int> LetterMap;
	int n = 0;
	for (int i = 0; i < FileSizeinBytes; i++) {
		//check if the key exists
		//if key found
		if (LetterMap.count(memblock[i]) == 1) {
			symbolFreq[LetterMap[memblock[i]]]++;
		} else {
			LetterMap[memblock[i]] = n;
			symbolList.push_back(memblock[i]);
			symbolFreq[n]++;
			n++;
		}
	}
	no_of_symbols = n;
	cout << "total no of symbols: " << n << endl;
	//Check the frequency
//	  for(int i = 0; i < no_of_symbols; i++){
//			cout << "freq of " << i << " is " << symbolFreq[i] << endl;
//		}

}
