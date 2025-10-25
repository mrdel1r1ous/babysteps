#include <iostream>
#include <csignal>
#include <clocale>
#include "time_lib.h"
using namespace std;

int main(int argc, char** argv) {

	signal(SIGINT, SIG_IGN);
	signal(SIGBREAK, SIG_IGN);

	setlocale(LC_ALL, "Russian");
	int x, i1, i2, m;
	string s1, s2;
	cout << "Формат ввода: 0 - в секундах, 1 - в формате чч:мм:сс." << endl
		<< "Выберите формат ввода: ";
	cin >> x;

	switch (x) {
	case 0: {
		i1 = timelab::getTimeI();
		i2 = timelab::getTimeI();
		break;
	}
	case 1: {
		s1 = timelab::getTimeS();
		s2 = timelab::getTimeS();
		i1 = timelab::strToTime(s1);
		i2 = timelab::strToTime(s2);
		break;
	}
	default: {
		cout << "Неверный ввод.";
		return 0;
	}
	}

	cout << "Время 1: " << i1 << " " << timelab::timeToStr(i1) << endl
		<< "Время 2: " << i2 << " " << timelab::timeToStr(i2) << endl;

	cout << "0 - сложение, 1 - вычитание:" << endl;
	cin >> x;
	if ((x != 0) && (i2 > i1)) cout << "Отрицательный результат, вычесть нельзя!";
	else {
		m = timelab::addTime(x, i1, i2);
		cout << "Результат: " << m << " " << timelab::timeToStr(m) << endl;
	}

	return 0;
}