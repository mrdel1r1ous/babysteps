#ifndef NOTE_LIB
#define NOTE_LIB

namespace note {

	void input_clear();
	_crt_signal_t sigIgnore();
	int getInt();

	struct MusicNote {
		int pitch; int duration; int volume;
		struct MusicNote(int p, int d, int v) : pitch(p), duration(d), volume(v) {}
		void display();
	};

	MusicNote *cmpPitch(MusicNote *note1, MusicNote *note2);
	MusicNote *setPitch(MusicNote *note, int pitch);
	MusicNote *setVolume(MusicNote *note, int volume);

}

#endif