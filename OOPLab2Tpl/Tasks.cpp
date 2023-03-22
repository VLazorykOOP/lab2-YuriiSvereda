#include <iostream>
#include <bitset>
#include <fstream>
#include <ios>

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

void WriteBinFile(unsigned short ARR[16][16], const char* fileName) {
    ofstream Pew("binary.dat", ios::out | ios::binary);
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            Pew.write((const char*)&ARR[i][j], sizeof(unsigned short));
        }
    }
    Pew.close();

}

void ReadBinFile(unsigned short ARR[16][16], const char* fileName) {
    ifstream Pew("binary.dat", ios::in | ios::binary);
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            Pew.read((char*)&ARR[i][j], sizeof(unsigned short));
        }
    }
    Pew.close();
    return;
}

void ConsolTextInput(char Text[16][16]) {
    int i, j;
    //input of text:
    cout << "input text: " << '\n';
    for (i = 0; i < 16; i++) {
        cin.getline(Text[i], 16);
    }

    // filling in with spaces:
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            if (Text[i][j] == '\0') {
                for (int k = j; k < 16; k++) {
                    Text[i][k] = '_';
                }
            }
        }
    }
}

void WriteTextTextFile(char Text[16][16], const char* fileName)
{
    int i, j;
    ofstream fout(fileName);
    if (fout.fail()) return;
    for (i = 0; i < 16; i++) {
        fout << endl;
        for (j = 0; j < 16; j++) {
            fout << Text[i][j];
        }
    }
    fout.close(); 
}

void EncriptionText() {
    char text[16][16];
    int i, j;
    unsigned char current_value;
    unsigned short encryption_variable, t;
    unsigned short result[16][16];
    bool b;

    ConsolTextInput(text);
    //output of a text array:
    WriteTextTextFile(text, "EnteredText.txt");

    //encryption of the text:
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            encryption_variable = 0;
            current_value = text[i][j];
            t = current_value;
            encryption_variable |= i;       //number of the row
            t <<= 12;
            encryption_variable |= t >> 8;   //yunger ASCII

            t = 1;
            b = 0;
            for (unsigned short k = 0; k < 8; k++) // calculating the parity bit of the first 2 fields
            {
                if (encryption_variable & t) {
                    if (b == 0) b = 1; else b = 0;
                }
                t <<= 1;
            }
            encryption_variable |= b << 8;

            t = current_value;
            t >>= 4;
            encryption_variable |= t << 9;  //older ASCII
            encryption_variable |= j << 13; //number of the position of the character in the string

            t = 1;
            b = 0;
            for (unsigned short k = 0; k < 8; k++) // calculating the parity bit of the previous 2 fields
            {
                if (encryption_variable & t) {
                    if (b == 0) b = 1; else b = 0;
                }
                t <<= 1;
            }
            encryption_variable |= b << 15;

            result[i][j] = encryption_variable;
            cout << std::bitset<16>(result[i][j]) << '\n';
            WriteBinFile(result, "Result.bin");
        }
    }
}

void UnencriptionText() {
    int i, j;
    char unencriptedText[16][16];
    unsigned short unencrypted_i_index = 0, unencrypted_j_index = 0, true_ascii, e, current_value;
    unsigned short result[16][16];
    ReadBinFile(result, "Result.bin");
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 4; j++) {
            // unencryption of the row numer:
            unencrypted_i_index = 0;
            unencrypted_i_index |= result[i][j] << 12;
            unencrypted_i_index = unencrypted_i_index >> 12;
            // unencryption number of the position of the character in the string:
            unencrypted_j_index |= result[i][j] << 1;
            unencrypted_j_index = unencrypted_j_index >> 14;
            // unencryption of the yunger ASCII:
            e = result[i][j] << 8;
            e = e >> 12;
            true_ascii = e;
            // unencryption of the older ASCII:
            e = result[i][j] << 3;
            e = e >> 12;
            e = e << 4;
            true_ascii |= e;
            //writing unencrypted data to an array:
            unencriptedText[unencrypted_i_index][unencrypted_j_index] = static_cast<char>(true_ascii);
        }
    }
    for (i = 0; i < 16; i++) {
        cout << endl;
        for (j = 0; j < 16; j++) {
            cout << unencriptedText[i][j];

        }
    }
    WriteTextTextFile(unencriptedText, "UnencriptedText.txt");

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
    EncriptionText();
    UnencriptionText();
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
			if (b1 == 1) {
				a1 += a;
				b1--;
			}
			else {
				a1 += a << 1;
				b1 -= 2;
			}
		}
		cout << "Rerult: " << a1 << endl;
		cout << "Audit: " << a * b << endl;
}


