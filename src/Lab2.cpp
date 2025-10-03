#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <csignal>
#include <clocale>
#include <cmath>
using namespace std;

_crt_signal_t sigIgnore() {
	cin.clear();
	return SIG_IGN;
}

int main(int argc, char** argv) {

	setlocale(LC_ALL, "Russian");

	double radius = -1, result = 0;

	cout << "Введите радиус окружности от 0 до 100: " << endl;
	
	while (1) {

		signal(SIGINT, sigIgnore());
		signal(SIGBREAK, sigIgnore());

		if (!(cin >> radius)) {
			cin.clear();
			cout << endl << "Не стоит это нажимать." << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		else if ((radius < 0) || (radius > 100)) {
			cin.clear();
			cout << "Этот радиус вне диапазона значений!" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		else break;
	}

	result = radius * M_PI;

	cout << "Длина окружности с точностью до 10^-9: " << fixed << setprecision(9) << result << endl;

	return 0;
}