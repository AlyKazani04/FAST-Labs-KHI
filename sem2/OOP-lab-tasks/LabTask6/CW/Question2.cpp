#include <iostream>
using namespace std;

class MediaFile{
	protected:
		string filepath;
		int size;
	public:
		MediaFile(int fs, string fp) : filepath(fp), size(fs) {}
		virtual void play(){
			cout<<"Playing."<<endl;
		}
		virtual void stop(){
			cout<<"Stopped Playing."<<endl;
		}
};

class VisualMedia : virtual public MediaFile{
	public:
		VisualMedia(int fs, string fp) : MediaFile(fs,fp) {}
		void play() override{
			cout<<"Visuals Playing."<<endl;
		}
};

class AudioMedia : virtual public MediaFile{
	public:
		AudioMedia(int fs, string fp) : MediaFile(fs,fp) {}
		void play() override{
			cout<<"Audio Playing."<<endl;
		}
};

class VideoFile : public VisualMedia, public AudioMedia{
	public:
		VideoFile(int fs, string fp) : MediaFile(fs, fp), VisualMedia(fs, fp), AudioMedia(fs, fp) {}
		void play() override{
			VisualMedia::play();
			AudioMedia::play();
		}
}; 

int main(int argc, char** argv){
	MediaFile* mediaptr[] = {
			new VideoFile(10, "Videos"),
			new VisualMedia(5, "Pictures"),
			new AudioMedia(8, "Audio")			
	};
	
	for(int i = 0; i < 3; i++){
		mediaptr[i]->play();
		mediaptr[i]->stop();
		cout<<endl;
	}
	
	for(int i = 0; i < 3; i++){
		delete mediaptr[i];
	}
	return 0;
}
