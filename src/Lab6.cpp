#include <iostream>
#include <csignal>
#include <clocale>
#include "note.h"
using namespace std;
using namespace note;

int main(int argc, char** argv) {

	setlocale(LC_ALL, "Russian");

	MusicNote *note1 = new MusicNote(1, 2, 3);
	MusicNote *note2 = new MusicNote(4, 5, 8);

	cout << "Значения нот (тон, длительность, громкость):" << endl;
	note1->display();
	note2->display();
	cout << "Новый тон ноты 1:" << endl;
	setPitch(note1, getInt());
	cout << "Новая громкость ноты 2:" << endl;
	setVolume(note2, getInt());
	cout << "Значения нот (тон, длительность, громкость):" << endl;
	note1->display();
	note2->display();
	cout << "Нота с более высоким тоном: " << endl;
	cmpPitch(note1, note2)->display();

	deleteNote(note1);
	deleteNote(note2);

	/*
	int* j;
	for (int i = 0; i < 100; i++) {
		j = new int[100];
	}
	delete j;
	*/

	return 0;
}