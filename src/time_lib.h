#pragma once

namespace timelab {
	std::string getTimeS();
	int getTimeI();
	int addTime(int sign, int time1, int time2);
	int strToTime(std::string time);
	std::string timeToStr(int timeI);
}

