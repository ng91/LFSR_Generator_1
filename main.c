/*
 ============================================================================
 /*
 ============================================================================
 Name        : LSFR_Generator_2.c
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
uint8_t newBit = 0;
uint8_t DCdetect = 0;
uint32_t generatedPattern = 0;

void setGeneratorSeed(uint8_t val){
	 // set a start bit sequence
	if(val == 0){
		shiftRegister = 0b1001011000000000;
	}
	if(val == 1){
		shiftRegister = 0b1001100101010111;
	}
	if(val == 2){
		shiftRegister = 0b0111010010100;
	}
}


uint8_t shiftRegisterXOR(uint16_t first, uint16_t second){
	uint16_t firstBit = shiftRegister & (1<<(first-1)) ;
	uint16_t secondBit = shiftRegister & (1<<(second-1));
	uint8_t output = 0;
	if(firstBit>0){
		firstBit = 1;
	} else {
		firstBit = 0;
	}
	if(secondBit>0){
		secondBit = 1;
	} else {
		secondBit = 0;
	}

	output = firstBit ^ secondBit;
	//if(shiftRegister == 65535){
	//	output=1;
	//}
	return output;
}
void putNewBit(uint8_t val){
	if(val>0){
		val=1;
	} else{
		val=0;
	}
	shiftRegister = (shiftRegister<<1) | val;
}

void putNewBitPattern(uint8_t val){
	if(val>0){
		val=1;
	} else{
		val=0;
	}
	generatedPattern = (generatedPattern<<1) | val;

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

showBytesPattern(uint32_t val){
	for(int i=0; i<32; i++){
		if(val & 1<<(31-i)){
			printf("1");
		}else{
			printf("0");
		}
	}
	printf("\n");
}

int main(void) {

//for(int x=0; x<3; x++){
	puts("NEW");
	setGeneratorSeed(0);
	for(int i=0; i<230; i++){
		newBit = shiftRegisterXOR(7,11);
		putNewBitPattern(newBit);
		putNewBit(newBit);
		printf("| Generated %d| , ", shiftRegister );
		showBytes(shiftRegister);
		showBytesPattern(generatedPattern);

	}
	printf("| Pattern %d| , ", generatedPattern );
	showBytesPattern(generatedPattern);
//}

	puts("END"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
