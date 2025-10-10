#include <iostream>
#include <csignal>
#include <clocale>
using namespace std;

_crt_signal_t sigIgnore() {
	cin.clear();
	return SIG_IGN;
}

unsigned int getUInt() {

	signal(SIGINT, sigIgnore());
	signal(SIGBREAK, sigIgnore());

	int i;

	while (!(cin >> i)) {
		cin.clear();
		cout << "Кнопки для ввода чисел находятся в другом месте." << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	if (i < 0) return -i;

	return i;
}

int main(int argc, char** argv) {

	setlocale(LC_ALL, "Russian");
	signal(SIGINT, sigIgnore());
	signal(SIGBREAK, sigIgnore());

	unsigned int x, n;

	cout << "Внимание: отрицательные числа будут конвертированы в положительные автоматически." << endl
		 << "Дробная часть вещественных чисел отбрасывается." << endl;
	cout << "Введите целое число:" << endl;
	x = getUInt();

	cout << "Введите номер бита, который нужно установить в 1: " << endl;
	n = getUInt();

	x = x | (1 << n);

	cout << "Число: " << x << endl;

	return 0;
}