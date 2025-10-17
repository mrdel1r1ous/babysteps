#include <iostream>
#include <csignal>
#include <clocale>
using namespace std;

_crt_signal_t sigIgnore() {
	cin.clear();
	return SIG_IGN;
}

int getUInt() {

	signal(SIGINT, sigIgnore());
	signal(SIGBREAK, sigIgnore());

	int i;

	while (!(cin >> i)) {
		cin.clear();
		cout << "Никак не надоест ломать меня, да?" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	if (i < 0) return -i;

	return i;
}

int main(int argc, char** argv) {

	setlocale(LC_ALL, "Russian");

	int a, b, n = 0;

	cout << "Внимание: отрицательные числа будут конвертированы в положительные автоматически." << endl
		 << "Дробная часть вещественных чисел отбрасывается." << endl
		 << "Введите A: " << endl;
	a = getUInt();
	cout << "Введите B: " << endl;
	b = getUInt();

	if (a > b) {
		swap(a, b);
		cout << "Неверный порядок чисел исправлен автоматически." << endl;
	}

	for (int i = a; i <= b; i++) {

		int x = i;
		int sum = 0;

		while (x > 0) {
			int last = x % 10;
			sum += last;
			x /= 10;
		}

		/*
		cout << "Сумма для " << i << " равна " << sum;
		^^ код для ручной проверки ^^
		*/

		bool f = false;

		if ((sum == 0) || (sum == 1)) f = true;

		else if (sum > 3)
			for (int j = 2; j <= (sum / 2); j++) {
				if (sum % j == 0) f = true;
			};
		
		if (!f) {
			n++;
			if ((n % 10 == 0)) {
				cout << "| " << i << "\t | Строка " << n / 10 << endl;
			}
			else cout << "| " << i << "\t";

			/*
			cout << "; найдено " << i << endl;
			^^ код для ручной проверки, закомментируй 72-75 ^^
			*/
		}

		if (n > 499) break;
	}

	return 0;
}