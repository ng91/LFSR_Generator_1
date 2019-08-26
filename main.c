/*
 ============================================================================
 Name        : LFSR_Generator_1.c
 Author      : ng
 Version     :
 Copyright   : Do not use!
 Description : Hello World in C, Ansi-style
 ============================================================================
 */






#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


uint16_t shiftRegister = 0;
uint8_t newVal = 0;


void setGeneratorSeed(){
	shiftRegister = 0b01110001000110; // set a start bit sequence
}

uint8_t linearFeedback(uint16_t first, uint16_t second){
	uint16_t firstBit = 1<<first-1;
	printf("|firstbit %d|\n", firstBit);
	uint16_t secondBit = 1<<second-1;
	printf("|firstbit %d|\n", secondBit);
	uint8_t result = 0;
	if((shiftRegister&&firstBit)>0){
		printf("| fbit|");
		firstBit = 1;
	} else {
		firstBit = 0;
	}
	if((shiftRegister&&secondBit)>0){
		printf("| sbit|");
		secondBit = 1;
	} else {
		secondBit = 0;
	}
	if((firstBit ^ secondBit)>0){
		result = 1;
	}else{
		result = 0;
	}

	printf("| result 3 %d|\n", result);
	return result;
}

showBytes(uint16_t val){
	for(int i=0; i<16; i++){
		if(val & 1<<(15-i)){
			printf("1");
		}else{
			printf("0");
		}
	}
	printf("\n");
}

void putNewBit(uint8_t val){
	if(val>0){
		val=1;
	} else{
		val=0;
	}
	shiftRegister = (shiftRegister<<1) | val;
}

int main(void) {
	setGeneratorSeed();
	for(int i=0; i<4; i++){
	newVal = linearFeedback(5, 4);
	putNewBit(newVal);
	printf("|LETTER %d|\n", shiftRegister);
	showBytes(shiftRegister);
	}

	puts("!!!END!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}


