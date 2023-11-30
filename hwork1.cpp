using namespace std;
#include <iostream>
#include <sstream>

//Валидация вводимых значений, провеерка на принадлежность к вещественным числам
double an_argument;

bool IsDouble()
{
	string myString;
	cin >> myString;
	istringstream iss{ (myString) };
	double f;
	iss >> noskipws >> f;
	if (iss.eof() && !iss.fail() and f > -10)
	{
		an_argument = f;
		return true;
	}
	else
	{
		cout << "Incorrect input, try again" << endl;
		return false;
	}
}
//функция поиска точки на графике
void find_y(double user_input)

{
	//определение принадлежности графику введенного значения условными операторами
	if (user_input <= -6)
	{
		//уравнение полукруга y = -1 * sqrt(R^2 - x^2)
		//r = 2, центр окружности (-8; 2)
		//(x+8)^2+(y-2)^2 = 4 
		//  (y-2)^2 = 4 - (x+8)^2
		//y = sqrt(4-(x+8))^2) + 2
		cout << "Y:\n" << -sqrt((4 - pow((user_input + 8), 2))) + 2 << endl;;
	}
	if (user_input > -6 && user_input <= -4)
	{
		//на графике фнукция параллельна оси Ox
		cout << "Y:\n" << 2 << endl;;

	}
	if (user_input == 0) {
		cout << "Y:\n" << 0 << endl;;
	}
	if (user_input > -4 && user_input < 2 && user_input != 0)
	{
		//k = -1/2 , функция y = kx + m	
		cout << "Y:\n" << -user_input / 2. << endl;;
	}
	if (user_input >= 2)
	{
		//функция y = kx + m    k = 1 m = -3
		cout << "Y:\n" << user_input - 3. << endl;;
	}
}

int main()
{
	while (1)
		if (IsDouble())
		{
			find_y(an_argument);
		}
}
