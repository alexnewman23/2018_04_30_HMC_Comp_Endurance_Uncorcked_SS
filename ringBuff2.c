// Shaun Sengupta
// DFR HMC Code - RING Buffer
// December 7 2016

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

const int SIZE = 5;

typedef struct {
	int buffer[SIZE];
	int readIdx;
	int writeIdx;
	int ringCounter;
} ring_buffer_t;

void addToRing (ring_buffer_t * rb, int x) {
	if(rb->ringCounter >= SIZE) {
		printf("Buffer is full\n");
		return;
	}


	rb->buffer[rb->writeIdx] = x;
	rb->writeIdx++;
	if (rb->writeIdx >= SIZE){
		rb->writeIdx = 0;
	}
	rb->ringCounter++;	

}

int readFromRing (ring_buffer_t * rb) {
	if (rb->ringCounter ==0) {
		printf("Buffer is empty\n");
		return 0;
	}
	int a;
	a = rb->buffer[rb->readIdx];
	rb->ringCounter--;
	rb->readIdx++;
	if (rb->readIdx >= SIZE)
	{
		rb->readIdx = 0;
	}

	return a;
}

bool isEmpty (ring_buffer_t * rb) {
	if (rb->ringCounter == 0){
		return true;
	} else{
		return false;
	}

}

ring_buffer_t new_ringBuf() {
	ring_buffer_t rb = { 
		.buffer = {}, 
		.readIdx = 0, 
		.writeIdx = 0, 
		.ringCounter = 0 
	}; 
	return rb;
}

int main(){
	ring_buffer_t ringBuf = new_ringBuf();
	ring_buffer_t ringBuf2 = new_ringBuf();

	addToRing(&ringBuf, 1);	
	addToRing(&ringBuf, 2);
	addToRing(&ringBuf, 3);
	addToRing(&ringBuf, 4);
	addToRing(&ringBuf, 5);

	addToRing(&ringBuf2, 500);
	
	for (int i = 0; i < 5; ++i)
	{
		printf("%d\n",readFromRing(&ringBuf));
	}
	
	addToRing(&ringBuf, 5);
	addToRing(&ringBuf, 6);
	addToRing(&ringBuf, 7);

	while(!isEmpty(&ringBuf)){
		printf("%d\n",readFromRing(&ringBuf));
	}
	printf("%d\n",readFromRing(&ringBuf2));


}