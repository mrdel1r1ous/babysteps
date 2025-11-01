#include <iostream>
#include <csignal>
#include <clocale>
#include "note.h"
using namespace std;

int main(int argc, char** argv) {

	setlocale(LC_ALL, "Russian");

	// All of the following requires instructions for
	// the user and console inputs for struct fields.
	note::MusicNote *note1 = new note::MusicNote(1, 2, 3);
	note::MusicNote *note2 = new note::MusicNote(2, 2, 3);

	note1->display();
	note::setPitch(note1, note::getInt());
	note::setVolume(note2, note::getInt());
	note1->display();
	note::cmpPitch(note1, note2)->display();

	delete note1;
	delete note2;

	return 0;
}