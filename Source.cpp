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







	return 0;
}