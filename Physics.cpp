#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

COORD cPos;
COORD Chars;
HANDLE hConsole;
string Str = "-1";
int Amount = 0; int Solve = 0; 
int const MaxAmount = 23;
string path;

void Random()
{
	int ProblemNumber = 0; int tmp;
	ifstream in("Random.txt");
	if (in.is_open())
	{		
		while (true)
		{
			ProblemNumber = rand() % MaxAmount + 1;
			while (!in.eof())
			{
				in >> tmp;
				if (tmp != ProblemNumber)
				{
					break;
				}
			}
			if (tmp != ProblemNumber)
			{
				break;
			}
		}
	}
	in.close();
	ofstream out("Random.txt", ios::app);
	if (out.is_open())
	{
		out << ProblemNumber << "\n";
	}
	out.close();

	ofstream outpath("Tmp.txt");
	if (outpath.is_open())
	{
		outpath << ProblemNumber;
	}
	outpath.close();

	ifstream input("Tmp.txt");
	if (input.is_open())
	{
		input >> path;
	}
	input.close();
}

int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);	
	srand(time(0));
	while (Amount < MaxAmount)
	{			
		Random();
		if (Amount != 0)
		{
			cPos.X = 0; cPos.Y = 15; SetConsoleCursorPosition(hConsole, cPos);
			SetConsoleTextAttribute(hConsole, 7);
			cout << Solve << "/" << Amount << "\n";
			float i = ((Solve + 0.00) / (Amount + 0.00)) * 100;
			cout << "Accuracy: " << i << "%\n";
		}
		ifstream in("Acheron\\7 Class\\" + path + ".txt");
		if (in.is_open())
		{
			getline(in, Str);
			cPos.X = 0; cPos.Y = 0; SetConsoleCursorPosition(hConsole, cPos);
			SetConsoleTextAttribute(hConsole, 7);
			cout << Str << "\n";
			SetConsoleTextAttribute(hConsole, 15);
			cin >> Str; 
			getline(in, Str);
			SetConsoleTextAttribute(hConsole, 7);
			cout << "\n\n" << Str;
			SetConsoleTextAttribute(hConsole, 2);
			cout << "\n 1 - верно";
			SetConsoleTextAttribute(hConsole, 4);
			cout << "\n 0 - неверно\n";			
		}
		in.close();	
		SetConsoleTextAttribute(hConsole, 15);
		while (Str != "1" && Str != "0")
		{
			cin >> Str;
		}
		if (Str == "1")
			Solve++;
		Amount++;
		system("cls");		
	}

	cPos.X = 0; cPos.Y = 15; SetConsoleCursorPosition(hConsole, cPos); SetConsoleTextAttribute(hConsole, 1);

	cout << "GG!\n\n\n\n";

	system("pause");

	return 0;
}