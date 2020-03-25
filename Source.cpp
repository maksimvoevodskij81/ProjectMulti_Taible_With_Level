#include<iostream>
#include<windows.h>
#include<ctime>


using namespace std;
int main()
{
	int multiplier1, multiplier2, corectResult, yourAnswer, points, minimumToGoNextLevel, level,menu;
	bool check = true;
	level = 0;
	minimumToGoNextLevel = 4 ;
	points = 0;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
start:
	for (;;)
	{

		for (int i = 1; i <= 10; i++)
		{
			srand(time(NULL));
			multiplier1 = rand() % 10;
			multiplier2 = rand() % 10 + 10 * level;
			corectResult = multiplier1 * multiplier2;
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\t\t" << multiplier1 << " * " << multiplier2 << " = ";
			cin >> yourAnswer;
			if (yourAnswer == corectResult)
			{
				points++;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\t" << "Corect!!!" << endl;
			}
			else
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED| FOREGROUND_INTENSITY);
				cout << "This is not the right answer !!!" << "\t" << "Corect result = " << corectResult << endl;
			}
		}
			if (points >= minimumToGoNextLevel)
		    {
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout <<"\t"<< "Congratulations you go to the next level !!!" <<endl<<"\t\t\t"<<++ level  << "LEVEL" << endl;;
			points = 0;
		    }
		else
		{
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "You did not score points for the next level !!!" << endl;
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << " Restart  1" << endl
				 << " The End  2" << endl;
			cin >> menu;
			switch (menu)
			{
			case 1:
				goto start;
				break;
			case 2:
				goto END;
				break;
			default:
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "\t" << "Choose from the options!!!" << endl;
				break;
			}
		}

	}
END:
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout <<"\t\t\t\t"<< "GOOG BYE" << endl;
	system("pause");
		return 0;
}



	
		
	


