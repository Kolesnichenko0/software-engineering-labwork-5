//Calculating an individual task 16
#include <iostream>
#include <fstream>
using namespace std;


//Checking the entered data
void checkValidInput()
{
	if (cin.fail())
	{
		throw "Input error";
	}
}

//Checking for step values
void checkVaildParams(float start, float step)
{
	if (step <= 0)
	{
		throw "Invalid data because step>0 ";
	}
}

//Checking the start and end values
void checkVaildParams(float start, float step, float end)
{
	if (start >= end)
	{
		throw "Invalid data, because start < end";
	}
}

//Checking for the value n
void checkVaildParams(float start, float step, float end, int n)
{
	if (n < 1)
	{
		throw "Invalid data, because n > =1 ";
	}
}

//Checking for the Save value
void checkVaildParams(float start, float step, float end, int n, int save)
{
	if (save != 0 && save != 1)
	{
		throw "Incorrect data, because you need to enter 0 or 1 ";
	}
}

//Finding the function value
float calculate(float x, int n)
{
	if (x > 0)
	{
		float y = 0;
		for (int i = 0; i <= n - 1; i++)
		{
			for (int j = 0; j <= n - 1; j++)
			{
				y = y + (x + j) / (i + j + 1);
			}
		}
		return y;
	}
	else
	{
		float y = 1;
		for (int i = 0; i <= n - 1; i++)
		{
			y = y * (i + i);
		}
		return y;
	}

}
//Print the desired values of the function, with the corresponding X on the interval with the specified step, and write to the output.txt optional
void printValues(float start, float step, float end, int n, int save)
{
	ofstream result("output.txt");
	for (float x = start; x <= end; x += step)
	{
		float y = calculate(x, n);
		cout << "x = " << x << " y = " << y << endl;
		if (save == 0)
		{
			result << "y = " << y << " x = " << x << endl;
		}
	}
	result.close();
}

int main()
{
	float start, step, end;
	int n, save;
	try
	{
		cout << "Enter 1 if you want to read the required data from the file" << endl;
		cout << "If you want to enter the required data, enter any numeric value other than 1:" << endl;
		double read; // Variable that is used to decide whether to read from a file or whether the user will enter data
		cin >> read;
		checkValidInput();
		if (read == 1)
		{
			ifstream inFile;
			inFile.open("text.txt");       //opening a text file  
			if (inFile)                    //checking whether the file is read or not
			{
				cout << "The file was read"<<endl;
			}
			else
			{
				throw "The file was not read";
			} 
			inFile >> start >> step;                           //reading the required data from a file
			checkVaildParams(start, step);
			inFile >> end;
			checkVaildParams(start, step, end);
			inFile >> n;
			checkVaildParams(start, step, end, n);
			inFile >> save;
			checkVaildParams(start, step, end, n, save);
		}
		else
		{
			cout << "Enter the start, step, end of the interval and n :" << endl;
			cout << "start = ";
			cin >> start;
			checkValidInput();

			cout << "step = ";
			cin >> step;
			checkValidInput();
			checkVaildParams(start, step);


			cout << "end = ";
			cin >> end;
			checkValidInput();
			checkVaildParams(start, step, end);

			cout << "n = ";
			cin >> n;
			checkValidInput();
			checkVaildParams(start, step, end, n);

			cout << "Enter 0 if you want to save all function values and the corresponding argument values, " << endl;
			cout << "Otherwise, if you don't want to save, enter 1:" << endl;
			cin >> save;
			checkValidInput();
			checkVaildParams(start, step, end, n, save);
		}
		printValues(start, step, end, n, save);
	}
	catch (const char* ex)
	{
		cout << ex << endl; // errors that were entered in throw
		return -1;
	}
	catch (...)
	{
		cout << "Unknown error" << endl; // All other unknown errors
		return -2;
	}
}
	