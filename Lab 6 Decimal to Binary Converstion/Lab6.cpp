#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
//precondition: none
//postcondition:The header and scale are output
void header();
//precondition: The file of binary inputs is declared
//postcondition: The binary number and its decimal equivalent are output
void converter();

string inputfile = "BinaryIn.dat";
int main()
{
	header();
	converter();
	return 0;
}
void header()
{
	cout << "\tBinary Number";
	cout << "\t\t\t\t\t\tDecimal Equivalent\n";
}
void converter()
{
	ifstream infile;
	infile.open(inputfile);
	char input;
	int decimalnum = 0, charcount = 0;
	bool firstchar = false, baddigit = false;
	infile.get(input);
	while (infile)
	{
		while (input != '\n' && infile)
		{
			if (input == '1' || firstchar && (input == '1' || input == '0'))
			{
				if (!firstchar)
					cout << "\t     ";
				charcount++;
				firstchar = true;
				cout << input;
				decimalnum *= 2;
				if (input == '1')
				{
					decimalnum++;
				}
			}
			else if (input != ' ' || (input == ' ' && firstchar))
			{
				for (int i = 0; i < charcount; i++)
					cout << '\b';
				cout << "bad digit on input\n";
				baddigit = true;
				infile.ignore(256, '\n');
				break;
			}
			infile.get(input);
		}
		if (baddigit == false)
		{
			for (int i = 0; i < (48 - charcount); i++)
				cout << " ";
			cout << decimalnum << endl;
		}
		firstchar = false;
		baddigit = false;
		infile.get(input);
		decimalnum = 0;
		charcount = 0;
	}
}