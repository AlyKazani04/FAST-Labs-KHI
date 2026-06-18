#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Media{
    protected:
        string title;
        string publicationDate;
        string uniqueID;
        string publisher;
        bool isCheckedOut; 
    public:
        Media(string t, string pubDate, string id, string pub) : 
            title(t), publicationDate(pubDate), uniqueID(id), publisher(pub), isCheckedOut(false) {}
        virtual void displayinfo(){
            cout<<"Title: "<<title<<endl;
            cout<<"Publication Date: "<<publicationDate<<endl;
            cout<<"Unique ID: "<<uniqueID<<endl;
            cout<<"Publisher: "<<publisher<<endl;
        }
        virtual void checkOut(){
            if(!isCheckedOut){
                isCheckedOut = true;
                cout<<title<<" has been checked out."<<endl;
            } else{
                cout<<title<<" is already checked out."<<endl;
            }
        }
        virtual void returnItem(){
            if(isCheckedOut){
                isCheckedOut = false;
                cout<<title<<" has been returned."<<endl;
            } else{
                cout<<title<<" was not checked out."<<endl;
            }
        }
        string getTitle(){ 
            return title; 
        }
        string getPublicationDate(){
            return publicationDate;
        }
};

class Book : public Media{
    private:
        string author;
        string ISBN;
        int numberOfPages;
    public:
        Book(string t, string pubDate, string id, string pub, string auth, string isbn, int pages) : 
            Media(t, pubDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}
        void displayinfo() override{
            Media::displayinfo();
            cout<<"Author: "<<author<<endl;
            cout<<"ISBN: "<<ISBN<<endl;
            cout<<"Pages: "<<numberOfPages<<endl;
        }
};

class DVD : public Media{
    private:
        string director;
        int duration; // in minutes
        string rating;
    
    public:
        DVD(string t, string pubDate, string id, string pub, string dir, int dur, string rate)
            : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rate) {}
        
        void displayinfo() override{
            Media::displayinfo();
            cout<<"Director: "<<director<<endl;
            cout<<"Duration: "<<duration<<"min"<<endl;
            cout<<"Rating: "<<rating<<endl;
        }
    };

class CD : public Media{
    private:
        string artist;
        int numberOfTracks;
        string genre;
    public:
        CD(string t, string pubDate, string id, string pub, string art, int tracks, string gen) : 
            Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}
        void displayinfo() override{
            Media::displayinfo();
            cout<<"Artist: "<<artist<<endl;
            cout<<"Tracks: "<<numberOfTracks<<endl;
            cout<<"Genre: "<<genre<<endl;
        }
};

class Magazine : public Media{
    private:
        int issueNumber;
    public:
        Magazine(string t, string pubDate, string id, string pub, int isn) : 
            Media(t, pubDate, id, pub), issueNumber(isn){}
        void displayinfo() override{
            Media::displayinfo();
            cout<<"Issue Number: "<<issueNumber<<endl;
        }
};

Media* searchMediaByTitle(const vector<Media*>& mediaList, const string& title) {
    for (auto* media : mediaList) {
        if (media->getTitle() == title)
            return media;
    }
    return nullptr;
}

Media* searchMediaByYear(const vector<Media*>& mediaList, const string& year) {
    for (auto* media : mediaList) {
        if (media->getPublicationDate() == year)
            return media;
    }
    return nullptr;
}

int main(){
    vector<Media*> library;

    library.push_back(new Book("Reverend Insanity", "2015", "B001", "Gu Zhen Ren", "Gu Zhen Ren", "9780743273565", 33000));
    library.push_back(new DVD("Inception", "2010", "D001", "Warner Bros.", "Christopher Nolan", 148, "PG-13"));
    library.push_back(new CD("Thriller", "1982", "C001", "Epic Records", "Michael Jackson", 9, "Pop"));
    library.push_back(new Magazine("National Geographic", "2024", "M001", "NatGeo", 350));

    for (auto* media : library) {
        media->displayinfo();
        cout << "------------------------" << endl;
    }

    string searchTitle = "Reverend Insanity";
    Media* foundMedia = searchMediaByTitle(library, searchTitle);
    if (foundMedia) {
        cout << "Media found: " << endl;
        foundMedia->displayinfo();
    } else {
        cout << "Media not found." << endl;
    }

    // Clean up memory
    for (auto* media : library) {
        delete media;
    }

    return 0;
}