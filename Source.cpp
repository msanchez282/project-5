#include <iostream>
using namespace std;

// Matthew Sanchez and Alexander Gomez
//
// CPSC 240
//


// Q1
int b[4][4] = { 10, 20, 30, 40, 20, 10, 40, 30, 5, 15, 20, 25, 30, 25, 20, 15 };
int total = 0, i;
void displayNumOfAllShirts() {
	cout << "Total number of all shirts: " << total << endl;
}
void displayNumMedShirts() {
	cout << "Total number of medium shirts: " << total << endl;
}
void displayNumBlueShirts() {
	cout << "Total number of blue shirts: " << total << endl;
}
void displayNumShortSleeve() {
	cout << "Total number of short sleeve shirts: " << total << endl;
}
void displayNumRedShirts() {
	cout << "Total number of red shirts: " << total << endl;
}


// Q2
int c[5] = { 9, 3, 22, 8, 1 };
int x = 0, y = 0;
void displayOGArray() {
	cout << "Original array a: " << c[0] << ' ' << c[1] << " " << c[2] << " " << c[3] << " " << c[4] << endl;
}
void displayNewArray() {
	cout << "New array a: " << c[0] << ' ' << c[1] << " " << c[2] << " " << c[3] << " " << c[4] << endl;
}


// Q3
int a[3][3][2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };
void displayAllShirtsQ3() {
	cout << "Total number of all shirts: " << total << endl;
}

int main() {

	// Q1
	_asm {
		// display number of all shirts
		mov eax, 0;						// eax = 0
		mov i, 0;						// i = 0
		lea esi, [b];					// esi = [b]
	forloop:
		cmp i, 16;						// compare i & 16
		Je done;						// if equal jump to done
		add eax, [esi];					// eax += b[][]
		inc i;							// i++
		add esi, 4;						// esi += 4
		Jmp forloop;					// jump to forloop
	done:
		mov total, eax;					// total = eax
		call displayNumOfAllShirts;		// call function to display
		// display total number of medium shirts
		mov eax, 0;						// eax = 0
		mov i, 0;						// i = 0
		lea esi, [b];					// esi = [b]
		add esi, 4;						// esi + 4 = first medium shirt
	forloop2:
		cmp i, 4;						// compare i & 4
		Je done2;						// if i == 4 jump to done2
		add eax, [esi];					// eax += b[][]
		inc i;							// i++
		add esi, 16;					// esi+=16, to skip to next medium size color
		Jmp forloop2;					// jump to forloop2
	done2:
		mov total, eax;					// total = eax
		call displayNumMedShirts;		// call function to display
		// display total of blue shirts
		mov eax, 0;						// eax = 0
		mov i, 0;						// i = 0
		lea esi, [b];					// esi = [b]
		add esi, 32;					// esi + 32 = first blue shirt
	forloop3:
		cmp i, 4;						// compare i & 4
		Je done3;						// if i == 4, jump done3
		add eax, [esi];					// eax += b[][]
		inc i;							// i++
		add esi, 4;						// esi += 4 for next blue shirt
		Jmp forloop3;					// Jump to forloop3
	done3:
		mov total, eax;					// total = eax
		call displayNumBlueShirts;		// call function to display
	}

	cout << endl << endl;

	// Q2
	_asm {
		call displayOGArray;
		lea esi, [c];
	outerLoop:
		cmp x, 5;
		Je q2done;
		mov eax, 0;
	innerLoop:
		add eax, [esi];
		add esi, 4;
		cmp eax, [esi];
		Jg outerLoop;
		xchg eax, [esi];
		inc x;
		inc y;
		Jmp outerLoop;
	q2done:
		call displayNewArray;
	}


	cout << endl << endl;


	// Q3
	_asm {
		// calculate number of all shirts
		mov eax, 0;						// eax = 0
		mov i, 0;						// i = 0
		lea esi, [a];					// esi = [a]
	forloopQ3:
		cmp i, 18;						// compare i & 18
		Je doneQ3;						// if i == 18, jump to doneQ3
		add eax, [esi];					// eax += b[][][]
		inc i;							// i++
		add esi, 4;						// esi += 4 for next int in array
		Jmp forloopQ3;
	doneQ3:
		mov total, eax;
		call displayAllShirtsQ3;
		// calculate number of medium shirts
		mov eax, 0;
		lea esi, [a];
		add esi, 8;						// esi + 8	|| b[0][1][0]
		add eax, [esi];
		add esi, 4;						// esi + 12 || b[0][1][1]
		add eax, [esi];
		add esi, 20;					// esi + 32 || b[1][1][0]
		add eax, [esi];
		add esi, 4;						// esi + 36 || b[1][1][1]
		add eax, [esi];
		add esi, 20;					// esi + 56 || b[2][1][0]
		add eax, [esi];
		add esi, 4;						// esi + 60 || b[2][1][1]
		mov total, eax;
		call displayNumMedShirts;
		// calculate number of short sleeve shirts || b[][][0]
		mov eax, 0;
		lea esi, [a];					// esi || b[0][0][0]
		add eax, [esi];
		add esi, 8;						// esi + 8 || b[0][1][0]
		add eax, [esi];
		add esi, 8;						// esi + 16 || b[0][2][0]
		add eax, [esi];
		add esi, 8;						// esi + 24 || b[1][0][0]
		add eax, [esi];
		add esi, 8;						// esi + 32 || b[1][1][0]
		add eax, [esi];
		add esi, 8;						// esi + 40 || b[1][2][0]
		add eax, [esi];
		add esi, 8;						// esi + 48 || b[2][0][0]
		add eax, [esi];
		add esi, 8;						// esi + 56 || b[2][1][0]
		add eax, [esi];
		add esi, 8;						// esi + 64 || b[2][2][0]
		add eax, [esi];
		mov total, eax;
		call displayNumShortSleeve;
		// calculate number of red shirts || b[0][][]
		mov eax, 0;
		lea esi, [a];				// esi = b[0][0][0]
		add eax, [esi];
		add esi, 4;					// esi + 4 = b[0][0][1]
		add eax, [esi];
		add esi, 4;					// esi + 8 = b[0][1][0]
		add eax, [esi];
		add esi, 4;					// esi + 12 = b[0][1][1]
		add eax, [esi];
		add esi, 4;					// esi + 16 = b[0][2][0]
		add eax, [esi];
		add esi, 4;					// esi + 20 = b[0][2][1]
		add eax, [esi];
		mov total, eax;
		call displayNumRedShirts;
	}





	return 0;
}