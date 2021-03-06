

#include "pch.h"
#include <iostream>
#include <functional>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <ctime>
#include <string>
#include <numeric>
#include <sstream>

double MultiBy2(double num) {
	return num * 2;
}

double MultiBy3(double num) {
	return num * 3;
}

double doMath(std::function<double(double)> func, double num) {
	return func(num);
}

bool isItOdd(int num) {
	if (num % 2 == 0) {
		return false;
	}
	else {
		return true;
	}
}

std::vector<int> ChangeListToOdd(std::vector<int>List, std::function<bool(int)> func) {
	std::vector<int> rtnVec;
	for (auto i : List) {
		if (func(i)) {
			rtnVec.push_back(i);
		}
	}
	return rtnVec;
}

std::vector<char> GenerateRdmValue(std::vector<char>Possibility, int numberValues) {
	std::vector<char> rtnVecOfChars;
	srand(time(NULL));
	for (int x = 0; x < numberValues; ++x) {
		int number = rand() % 2;
		rtnVecOfChars.push_back(Possibility[number]);
	}
	return rtnVecOfChars;
}

int getNumberOf(std::vector<char>List, char Value) {
	int count = 0;
	for (char c : List) {
		if (c == Value) {
			count++;
		}
	}
	return count;
}

int main()
{

	std::cout << "Hello World!\n"; 
	

	std::cout << MultiBy2(3)<<"\n";
	std::cout << doMath(MultiBy3, 3)<<"\n";
	std::vector<int> Lista = { 1,2,3,4,5,6,7,8,9,11,13,4,22,33,44,5,4,3,2,3,55,77 };
	std::vector<int> OddList = ChangeListToOdd(Lista, isItOdd);
	for (auto x : OddList) {
		std::cout << x << " , ";
	}

	std::vector<char> Poss = { 'H','T' };
	std::vector<char> Los = GenerateRdmValue(Poss, 200);

	std::cout << "\nH : " << getNumberOf(Los, 'H');
	std::cout << "\nT : " << getNumberOf(Los, 'T');
}

