// pr2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Conio.h>
#include<Windows.h>
#include<String.h>
void init();// функция инициализации
void OutputCars();// функция вывода данных
void PutCars();// функция ввода данных
void AddCars();// функция добавления данных
int zashita(char putt[]);// функция для защиты от букв
void SellCars();// функция удаления записи
void NewPrice();// функция изменения цены
void SumCars();// функция подсчета цены авто
void deinit();// функция очищения памяти
typedef struct
{
	char name[20];// марка авто
	char color[20];// цвет авто
	int year;// год выпуска
	double price;// цена
}cars;// структура машины
cars *car;// массив машин
int n;// кол-во машин
void init()// функция инициализации
{
	car = (cars*)calloc(20, sizeof(cars));// выделение памяти под массив
	if (car == NULL)// проверка что память выделилась
	{
		printf("Недостаточно памяти, завершение работы");
		getch();
		exit(1);
	}
	*car = { "Toyota", "черный", 2020, 2000000 };
	*(car + 1) = { "BMW", "белый", 2020, 1000000 };
	*(car + 2) = { "LADA", "зеленый", 2020, 500000 };
	n = 3;
	printf("Машины проиниализированы\n\n");
	printf("Для продолжения нажмите любую клавишу.");
	getch();

}

void deinit()// функция очищения памяти
{
	system("cls");
	free(car);
	printf("\n Память успешно очищена, для выхода нажмите любую клавишу");
	getch();
}
void OutputCars()// функкция вывода данных
{
	system("cls");
	if (n != 0)
	{
		printf("***********************************************************************************************\n");
		printf("*номер*      марка/адресс    *     цвет/адресс    *      год/адресс    *      цена/адресс     *\n");
		printf("***********************************************************************************************\n");
		for (int i = 0; i < n; i++)
		{
			printf("*%5d*%12s/%9d*%10s/%9d*%10d/%9d*%12.2lf/%9d*\n", i + 1, (car + i)->name, &(car + i)->name, (car + i)->color, &(car + i)->color, (car + i)->year, &(car + i)->year, (car + i)->price, &(car + i)->price);
			printf("*     *                      *                    *                    *                      *\n");
			if (i != n - 1)printf("***********************************************************************************************\n");
		}
		printf("***********************************************************************************************\n\n");
	}
	else
	{
		printf("\nсписок машин пуст, введите данные");
		getch();
	}
}

void PutCars()// функция ввода данных
{
	char putt[20];// доп массив
	int f;// флажок для проверки на некорректный ввод
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		fflush(stdin);
		printf("  Машина номер %d\n\n", i + 1);
		printf(" Марка машины: ");
		gets((car + i)->name);
		fflush(stdin);
		printf(" Цвет машины: ");
		gets((car + i)->color);
		do{
			printf(" Год выпуска машины: ");
			fflush(stdin);
			gets_s(putt);
			fflush(stdin);
			f = zashita(putt);// проверка на некорректный ввод
			if (f) { printf("\nгод выпуска должна содержать только цифры, попробуйте еще раз\n"); }
		} while (f);
		(car + i)->year = atoi(putt);// перевод строки в int
		for (int k = 0; k < 20; k++)
			putt[k] = '\0';// очистка массива
		do{
			printf(" Цена: ");
			fflush(stdin);
			gets_s(putt);
			fflush(stdin);
			f = zashita(putt);// проверка на некорректный ввод
			if (f) { printf("\nцена должна содержать только цифры, попробуйте еще раз\n"); }
		} while (f);
		(car + i)->price = atof(putt);
		for (int k = 0; k < 20; k++)
			putt[k] = '\0';// очистка массива
		system("cls");
	}

}

void AddCars()// функция добавления данных
{
	system("cls");
	char putt[20];// доп массив
	int f;// флажок для проверки на некорректный ввод
	do
	{
		if (n > 20)// проверка на макс кол-во авто
		{
			printf("Достигнуто максимальное кол-во машин\n");
			printf("Ввод окончен, для продолжения нажмите любую клавишу\n");
			_getch();
			break;
		}
		system("cls");
		fflush(stdin);
		printf("  Машина номер %d\n\n", n + 1);
		printf(" Марка машины: ");
		gets((car + n)->name);
		fflush(stdin);
		printf(" Цвет машины: ");
		gets((car + n)->color);
		do{
			printf(" Год выпуска машины: ");
			fflush(stdin);
			gets_s(putt);
			fflush(stdin);
			f = zashita(putt);// проверка на некорректный ввод
			if (f) { printf("\nгод выпуска должен содержать только цифры, попробуйте еще раз\n"); }
		} while (f);
		(car + n)->year = atoi(putt);// перевод строки в int
		for (int i = 0; i < 20; i++)
			putt[i] = '\0';// очистка массива
		do{
			printf(" Цена: ");
			fflush(stdin);
			gets_s(putt);
			fflush(stdin);
			f = zashita(putt);
			if (f) { printf("\nцена должна содержать только цифры, попробуйте еще раз\n"); }
		} while (f);
		(car + n)->price = atof(putt);// перевод строки в double
		for (int i = 0; i < 20; i++)
			putt[i] = '\0';
		n++;
		printf("Продолжить ввод? Нет - Esc; Да - любая клавиша\n");
	} while (_getch() != 27);
	system("cls");
}
int zashita(char putt[])
{
	int f1;// флажок для отслежки букв строке
	f1 = 0;
	for (int i = 0; putt[i] != '\0'; i++)
	{
		if ((putt[i]<48 || putt[i]>57) && putt[i] != 46 && putt[i] != 43 && putt[i] != 32) { f1 = 1; break; }// условие некорректного ввода
	}
	return f1;
}

void SellCars()
{
	int number;// номер проданной машины
	OutputCars();// вывод данных
	do{
		printf("\n Введите номер проданной машины: ");
		scanf("%d", &number);
		if (number<1 || number>n)printf("\nВведен некорректный номер, попробуйте еще раз\n");// проверка на некорректный ввод
	} while (number<1 || number>n);
	for (int i = number; i < n; i++)
	{
		*(car + i - 1) = *(car + i);// сдвиг с помощью присваивания одного указателя другому
	}
	n--;// уменьшение кол-ва машин
	printf("\n машина успешно продана, для продолжения нажмите любую клавишу");
	getch();
}

void NewPrice()// функция изменения цены
{
	char putt[20];// доп массив
	int number;// номер машины
	int f;// флажок для проверки на некорректный ввод
	OutputCars();// вывод данных
	do{
		printf("\n Введите номер машины: ");
		scanf("%d", &number);
		if (number<0 || number>n) printf("Введен недопустимый номер, попробуйте еще раз\n");
	} while (number<0 || number>n);// проверка на корректный ввод
	do{
		printf(" Новая цена: ");
		fflush(stdin);
		gets_s(putt);
		fflush(stdin);
		f = zashita(putt);
		if (f) { printf("\nцена должна содержать только цифры, попробуйте еще раз\n"); }
	} while (f);
	(car + number - 1)->price = atof(putt);// перевод строки в double
	for (int i = 0; i < 20; i++)
		putt[i] = '\0';
	printf("\nЦена успешно изменена, для продолжения нажмите любую кдлавишу");
	getch();
}

void  SumCars()// функция подсчета цены машин
{
	int f;// флажок для проверки на корректный ввод
	int count;// кол-во выбранных машин
	int Number[20];// номера выбранных машин
	char *ptr;// указатель для работы со строкой
	char str[50];// входная строка
	double sum;// искомая сумма
	bool f1 = false;// флажок для проверки на корректный ввод
	OutputCars();// вывод данных
	do{
		f1 = false;// начальное положение флажка
		do{
			printf("\nВведите через пробел номера машин, цены которых необходимо сложить:\n");
			fflush(stdin);
			gets(str);
			fflush(stdin);
			f = zashita(str);// функция защиты от букв
			if (f) {
				printf("\nвведены недопустимые значения или пустая строка, попробуйте еще раз\n");
				for (int k = 0; k < 50; k++)
					str[k] = '\0';
			}
		} while (f);
		ptr = strtok(str, " ");// начальное разбиение строки на слова
		count = 0;// начальное кол-во номеров машин
		while (ptr != NULL)
		{
			Number[count] = atoi(ptr);// перевод строки в int
			ptr = strtok(NULL, " ");// продолжение разбиения строки
			count++;
		}
		for (int i = 0; i < count; i++)// проверка на корректный ввод
		{
			if (Number[i]<1 || Number[i]>n) f1 = true;
		}
		if (count<2 || count>n || f1){ printf("\nвведены недопустимые значения, попробуйте еще раз\n"); }
	} while (count<2 || count>n || f1);
	sum = 0;// начальная сумма цены
	for (int i = 0; i < count; i++)
	{
		sum += (car + Number[i] - 1)->price;
	}
	system("cls");
	OutputCars();// вывод данных
	printf("Стоимость машин под номером ");
	for (int i = 0; i < count; i++)
	{
		printf("%d ", Number[i]);// вывод суммы
	}
	printf("равна: %.3lf рублей\n\n", sum);
	printf("Для продолжения нажмите любую клавишу.");
	getch();
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);// подключение русскоязычного ввода/вывода
	SetConsoleOutputCP(1251);
	init();// функция инициализации
	char cas;// выбор пользователя
	do{
		system("cls");
		printf("  Выберите действие:\n\n");
		printf(" 1 - ввести данные\n");
		printf(" 2 - вывод данных\n");
		printf(" 3 - добавить машину\n");
		printf(" 4 - продать машину\n");
		printf(" 5 - изменить цену машины\n");
		printf(" 6 - посчитать стоимость нескольких машин\n");
		printf(" 0 - выход из программы\n");
		bool f;
		do{
			f = true;
			cas = _getch();
			switch (cas)
			{
			case '1': PutCars(); break;
			case '2': OutputCars(); printf("Для продолжения нажмите любую клавишу."); getch(); break;
			case '3': AddCars(); break;
			case '4': SellCars(); break;
			case '5': NewPrice(); break;
			case '6': SumCars(); break;
			case '0': deinit(); break;
			default: printf("такого варианта нет, попробуйте еще раз\n"); f = false; break;
			}
		} while (!f);
	} while (cas != '0');
	return 0;
}

