#include <iostream>
#include <csignal>
#include <string>
#include "note.h"

namespace note {

	void input_clear() {
		std::cin.clear();
		std::cout << "Неверный ввод." << std::endl;
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

		return i;
	}

	MusicNote *cmpPitch(MusicNote *note1, MusicNote *note2) {
		if (note1->pitch > note2->pitch) return note1;
		return note2;
	}

	void setPitch(MusicNote *note, int pitch) {
		if (note != nullptr) note->pitch = pitch;
	}

	void setDuration(MusicNote* note, int duration) {
		if (note != nullptr) note->duration = duration;
	}

	void setVolume(MusicNote *note, int volume) {
		if (note != nullptr) note->volume = volume;
	}

	void deleteNote(MusicNote* note) {
		if (note!=nullptr) delete note;
	}

	void MusicNote::display() {
		std::cout << pitch << " " << duration << " " << volume << std::endl;
	}

}