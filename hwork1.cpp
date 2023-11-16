using namespace std;
#include <iostream>
#include <string>

string check_str;
double an_argument;
//Валидация вводимых значений, провеерка на принадлежность к вещественным числам
bool isCorrectNum(string check_string)
{
	//Маркеры, показывающее, встречалась ли в строке буква или точка хотя бы раз
	bool isPointer = false;
	bool isSign = false;
	
	//искоючаем наличие разделителя за пределами цифр числа
	if (check_str[0] == '.' or check_str.back() == '.' )
	{
		return false;
	}
	//перебираем число на наличие точек между цифрами
	for (int i = 1; i < check_str.size(); i++)
	{
		if (check_str[i] == '.' )
		{
			if (isPointer == false)
			{
				if (!isdigit(check_str[0])  and !isdigit(check_str[1])) return false;
			
					isPointer = true;// точка найдена, и она стоит гарантированно после числа
					continue;
						}
			else return false;// если найдено больше 1 точки ,бракуем
		}
		
	}
	for(int i = 0; i<check_str.size(); i++)
	{
		
		if (check_str[i] == '-')
		{
			if (isSign == false and check_str[0] == '-') 
			{
				isSign = true;
				continue;
			}
			else return false;

		}//проверка есть ли на первой итерации знак минуса, если есть ставим маркер, и если в следующих итерациях встретится минус, возвращаем false

		
	}
	for (char a : check_string)
	{
		if (a == '.' or isdigit(a) or a == '-')
		{
			continue;
		}
		else
		{
			return false;
		}
		//проверяем нет ли в нашей строке посторонних символов
	}
	return true;
	//Если после предыдущих проверок мы дошли до этой строчки, значит все условия соблюдены: минус, если есть, находится только в
	//стоит только одна точка и она строго после целой части, в записи нет посторонних символов
	}
//функция поиска точки на графике
void find_y() {
	//Ввод значения с клавиатуры
	
	cout << "Enter 'x':\n";
	cin >> check_str;

	if (isCorrectNum(check_str) == true)
	{
		an_argument = std::stod(check_str.substr());
		//определение принадлежности графику введенного значения условными операторами
		if (an_argument >= -10 && an_argument <= -6)
		{
			//уравнение полукруга y = -1 * sqrt(R^2 - x^2)
			//r = 2, центр окружности (-8; 2)
			//(x+8)^2+(y-2)^2 = 4 
			//  (y-2)^2 = 4 - (x+8)^2
			//y = sqrt(4-(x+8))^2) + 2

			double pre_compute = (4 - pow((an_argument + 8), 2));
			double func_y = -sqrt(pre_compute) + 2;
			cout << "Y:\n" << func_y << "\n";
			find_y();

		}
		if (an_argument >= -6 && an_argument <= -4)
		{
			//на графике фнукция параллельна оси Ox
			cout << 2<<"\n";
			find_y();
		}
		if (an_argument == 0) {
			cout << 0 << "\n"; find_y();//нижнее ветвление даёт минус ноль на вывод, мне это не понравилось, поэтому такая строчка заимела место быть.
		}
		if (an_argument >= -4 && an_argument <= 2)
		{
			//k = -1/2 , функция y = kx + m
			double  result = -an_argument / 2.;
			
			cout << result << "\n";
			find_y();
		}

		if (an_argument >= 2)
		{
			//функция y = kx + m k = 1 m = -3
			double  result = an_argument - 3.;
			cout << result << "\n";
			find_y();
		}
		if (an_argument <= -10)
		{
			//проверка выходим ли за значения Х, установленные заданием
			cout << "ERROR!\nTry other one\n";
			find_y();

		}
	}
	else
	{
		cout << "Incorrect input\n";
		find_y();
	}
}

int main()
{
	find_y();
}