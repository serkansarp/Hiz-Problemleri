// Hız Problemleri.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <clocale>
#include <iomanip>

using namespace std;

class Problem {
private:
	int problemTip;
	int yol;
	int arac1Hiz;
	int* arac2Hiz;
public:
	Problem(int, int, int, int);
	~Problem();
	int getProblemTip();
	int getYol()const;
	int getArac1Hiz()const;
	int getArac2Hiz()const;
	void problemiCoz(Problem&);
};