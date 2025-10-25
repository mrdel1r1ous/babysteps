#ifndef TIME_LIB
#define TIME_LIB

namespace timelab {
	std::string getTimeS();
	int getTimeI();
	int addTime(bool sign, int time1, int time2);
	int strToTime(std::string time);
	std::string timeToStr(int timeI);
}

#endif

