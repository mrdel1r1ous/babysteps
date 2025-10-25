#include <iostream>
#include <csignal>
#include <clocale>
#include "time_lib.h"
using namespace std;

int main(int argc, char** argv) {

	setlocale(LC_ALL, "Russian");

	string s = timelab::getTimeS();
	cout << s;

	return 0;
}