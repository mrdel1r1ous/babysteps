#ifndef NOTE_LIB
#define NOTE_LIB

namespace note {

	void input_clear();
	_crt_signal_t sigIgnore();
	int getInt();

	struct MusicNote {
		int pitch; int duration; int volume;
		MusicNote(int p, int d, int v) : pitch(p), duration(d), volume(v) {}
		~MusicNote() {}
		void display();
	};

	MusicNote *cmpPitch(MusicNote *note1, MusicNote *note2);
	void setPitch(MusicNote *note, int pitch);
	void setDuration(MusicNote *note, int duration);
	void setVolume(MusicNote *note, int volume);
	void deleteNote(MusicNote *note);
}

#endif