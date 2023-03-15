#include <iostream>
#include <bitset>
using namespace std;
#include "Tasks.h"
#include "Examples.h"
void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Calculation of expressions using bitwise operations  \n";
    cout << "    2.  Data encryption using bitwise operations \n";
    cout << "    3.  Data encryption using structures with bit fields \n";
    cout << "    4.  The problem of using bitwise operations \n";
    cout << "    5.  Examples of problems using bitwise operations \n";
    cout << "    6.  Exit \n";
}
void task1() {
    cout << " Calculation of expressions using bitwise operations  \n";
    unsigned int a, b, c;
    int x, y;
    cout << "Input a: ";
    cin >> a;
    cout << "Input b: ";
    cin >> b;
    cout << "Input c: ";
    cin >> c;
    x = ((((a << 4) + (a << 1)) + ((b << 8) + (b << 6) + (b << 1))) >> 9) - ((b << 7) - (b << 2) - (b << 1)) + ((c << 7) - (c << 2) - c);
    y = (18 * a + 312 * b) / 512 - b * 122 + c * 123;

    cout << "Result: " << x << endl << "Audit: " << y << endl;

    // Обчислення виразів з використанням побітових операцій
    // Calculation of expressions using bitwise operations 
}

void task2()
{
    // Шифрування даних з використання побітових операцій 
    // Data encryption using bitwise operations
    cout << " Data encryption using bitwise operations  \n";
	char text_input[16][4], text[16][16];
	int i, j;
	unsigned char c;
	unsigned short r, t, w;
	int result[16][16];
	bool b;


	//input of text
	for (i = 0; i < 16; i++) {
		cin.getline(text_input[i], 4);
	}
	//coping text in another variable to filling in with spaces
	for (i = 0; i < 16; i++) {
		for (j = 0; j < 16; j++) {
			text[i][j] = text_input[i][j];
		}

	}


	// filling in with spaces
	for (i = 0; i < 16; i++) {
		for (j = 0; j < 16; j++) {
			if (text[i][j] == NULL) {
				text[i][j] = ' ';
			}
		}
	}



	//encryption of the text
	for (i = 0; i < 16; i++) {
		for (j = 0; j < 16; j++) {
			w = text[i][j];
			r = i;
			w = j << 4;
			r |= w;    //number of the row
			w = text[i][j];
			r |= w << 4; //yung ASCII
			t = 1;
			b = false;
			for (unsigned short z = 0; z < 6; z++) // calculating the parity bit of the first 2 fields
			{
				if (r & t) {
					b = !b;
				}
				t <<= 1;
			}
			r <<= 1;
			r |= b;

			r |= w >> 9; //old ASCII

			w = j << 3;
			r |= w;
			for (unsigned short z = 0; z < 8; z++) // calculating the parity bit of the average field
			{
				if (r & t) {
					b = !b;
				}
				t <<= 1;
			}
			r <<= 1;//shift by 1 position for parity of the previous field
			r |= b; // adding parity to the previous field
			result[i][j] = r; //the encrypted character is added to the array
			cout << std::bitset<16>(result[i][j]) << " ";
		}cout << endl;

	}

}

void task3()
{
    // Шифрування даних з використання стуктур з бітовими полями 
    // Data encryption using structures with bit fields
    cout << "  Data encryption using structures with bit fields \n";
	cout << "sorry I didn't undertand this task";
}


void task4()
{   // Задача із використання побітових операцій
    // The problem of using bitwise operations
    cout << " Data encryption using structures with bit fields \n";
	using namespace std;
    #include <iostream>

		unsigned int a, b, a1 = 0, b1;
		cout << "input a value: ";
		cin >> a;
		cout << "input b value: ";
		cin >> b;
		b1 = b;
		while (b1 >= 1) {
			cout << endl << a1 << " " << b1 << endl;

			if (b1 == 1) {
				a1 += a;
				b1--;
			}
			else {
				a1 += a << 1;
				b1 -= 2;
			}
			cout << "Rerult: " << a1 << endl;
			cout << "Audit: " << a * b << endl;
		}
}


