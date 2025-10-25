#include <iostream>
#include <csignal>
#include <string>
#include "time_lib.h"
constexpr auto TIME_MAX = 86400;

namespace timelab {

	void input_clear() {
		std::cin.clear();
		std::cout << "Никак не надоест ломать меня, да?" << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	_crt_signal_t sigIgnore() {
		std::cin.clear();
		return SIG_IGN;
	}

	std::string getTimeS() {

		signal(SIGINT, sigIgnore());
		signal(SIGBREAK, sigIgnore());

		std::string s, x = ":";

		while (1) {
			std::cin >> s;
			if (std::cin.fail()) {
				input_clear();
				continue;
			}
			bool f = false;
			for (int i = 0; i < s.length(); i++)
				if (isalpha(s[i])) f = true;
			if (f) std::cout << "Неправильный ввод." << std::endl;
			else return s;
		}

		return s;
	}

	int getTimeI() {

		signal(SIGINT, sigIgnore());
		signal(SIGBREAK, sigIgnore());

		int i;
		while (!(std::cin >> i)) {
			input_clear();
		}

		if (i < 0) return 0;
		if (i > TIME_MAX) return TIME_MAX;
		return i;
	}

	int addTime(int sign, int time1, int time2)
	{
		if (sign == 0) return time1 + time2;
		return time1 - time2;
	}

	int strToTime(std::string timeS)
	{
		std::string inTime = timeS + ":";
		int timeI = 0, order = 0;
		std::string del = ":";
		auto pos = inTime.find(del);

		while (pos != std::string::npos) {

			std::string tmp = inTime.substr(0, pos);
			switch (order) {
			case 0:
				timeI = timeI + stoi(tmp) * 3600;
				break;
			case 1:
				timeI = timeI + stoi(tmp) * 60;
				break;
			default:
				timeI = timeI + stoi(tmp);
			}
			inTime.erase(0, pos+del.length());
			pos = inTime.find(del);
			order++;
		}

		return timeI;
	}

	std::string timeToStr(int timeI)
	{
		int inTime = timeI, order = 0;
		std::string timeS = "";
		while (order < 3) {
			switch (order) {
			case 0: {
				if ((inTime / 3600) < 10) timeS = timeS + "0" + std::to_string(inTime / 3600);
				else timeS = timeS + std::to_string(inTime / 3600);
				inTime = inTime % 3600;
				break;
			}
			case 1: {
				if ((inTime / 60) < 10) timeS = timeS + "0" + std::to_string(inTime / 60);
				else timeS = timeS + std::to_string(inTime / 60);
				inTime = inTime % 60;
				break;
			}
			default: {
				if (inTime < 10) timeS = timeS + "0" + std::to_string(inTime);
				else timeS = timeS + std::to_string(inTime);
				inTime = 0;
			}
			}
			if (order < 2) timeS = timeS + ":";
			order++;
		}
		return timeS;
	}

}