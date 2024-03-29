﻿// StdSimulation.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>

class RandomMethod {
	int randomNums[10];
	int seed;
	int count;
	int startNum = 2;
	int endNum = 6;

	int getPositionNum(int number, int startNum, int endNum) {
		number %= (int)pow(10, endNum);
		if (startNum > 0) {
			number /= (int)pow(10, startNum);
		}
		return number;
	}
	int getRandomNum(int seed) {
		long number = seed * seed;
		number = getPositionNum(number, startNum, endNum);
		return (int)number;
	}
	void clearRandomNums() {
		for (int i = 0; i < sizeof(randomNums) / sizeof(randomNums[0]); i++) {
			randomNums[i] = 0;
		}
	}
public:
	RandomMethod(int seed, int count) {
		this->seed = seed;
		this->count = count;
		for (int i = 0; i < sizeof(randomNums) / sizeof(randomNums[0]); i++) {
			randomNums[i] = 0;
		}
	};
	void setRandomNums() {
		for (int i = 0; i < count; i++) {
			randomNums[i] = getRandomNum(seed);
			seed = randomNums[i];
		}
	}

	void getRandomNums(int* inputArray, int arraySize) {
		int randomArrSize = sizeof(randomNums) / sizeof(randomNums[0]);
		//int thiscount = std::min(sizeof(inputArray)/sizeof(inputArray[0]), sizeof(randomNums)/ sizeof(randomNums[0]));
		int thiscount = std::min(randomArrSize, arraySize);
		for (int i = 0; i < thiscount; i++) {
			inputArray[i] = randomNums[i];
		}
		printf("thiscount %d", thiscount);
	}
	void printRandomNums(int count) {
		for (int i = 0; i < count; i++) {
			printf("random[%d]: %d \n", i + 1, randomNums[i]);
		}
	}

};

int main() {
	int seed = 0;
	int count = 0;
	printf("input seed value: ");
	scanf_s("%d", &seed);
	printf("Please enter the desired number: ");
	scanf_s("%d", &count);

	int myarray[5];
	for (int i = 0; i < 5; i++) {
		myarray[i] = 0;
	}
	RandomMethod s(seed, count);
	s.setRandomNums();
	s.printRandomNums(count);
	// get Array
	printf("-----get Array and print-----\n");
	s.getRandomNums(myarray, 5);
	for (int i = 0; i < count; i++) {
		printf("%d, ", myarray[i]);
	}
	printf("\n");


}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
