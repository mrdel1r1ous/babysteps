#include <iostream>
#include <csignal>
#include <string>
#include "note.h"
constexpr auto TIME_MAX = 86400;

namespace note {

	void input_clear() {
		std::cin.clear();
		std::cout << "Никак не надоест ломать меня, да?" << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	_crt_signal_t sigIgnore() {
		std::cin.clear();
		return SIG_IGN;
	}

	int getInt() {

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

	MusicNote *cmpPitch(MusicNote *note1, MusicNote *note2) {
		if (note1->pitch > note2->pitch) return note1;
		return note2;
	}

	MusicNote *setPitch(MusicNote *note, int pitch) {
		note->pitch = pitch;
		return note;
	}

	MusicNote *setVolume(MusicNote *note, int volume) {
		note->volume = volume;
		return note;
	}

	void MusicNote::display() {
		std::cout << pitch << " " << duration << " " << volume << std::endl;
	}

}