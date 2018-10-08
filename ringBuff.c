// Shaun Sengupta
// DFR HMC Code - RING Buffer
// December 7 2016

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

const int SIZE = 5;
int buffer[SIZE] = {0} ;
int readIdx = 0;
int writeIdx = 0;
int ringCounter = 0;

void addToRing (int x) {
	if(ringCounter >= SIZE) {
		printf("Buffer is full\n");
		return;
	}


	buffer[writeIdx] = x;
	writeIdx++;
	if (writeIdx >= SIZE){
		writeIdx = 0;
	}
	ringCounter++;	

}

int readFromRing () {
	if (ringCounter ==0) {
		printf("Buffer is empty\n");
		return 0;
	}
	int a;
	a =  buffer[readIdx];
	ringCounter--;
	readIdx++;
	if (readIdx >= SIZE)
	{
		readIdx = 0;
	}

	return a;
}

bool isEmpty () {
	if (ringCounter == 0){
		return true;
	} else{
		return false;
	}

}

int main(){

	addToRing(1);	
	addToRing(2);
	addToRing(3);
	addToRing(4);
	addToRing(5);
	
	for (int i = 0; i < 5; ++i)
	{
		printf("%d\n",readFromRing());
	}
	
	addToRing(5);
	addToRing(6);
	addToRing(7);

	while(!isEmpty()){
		printf("%d\n",readFromRing());
	}

}