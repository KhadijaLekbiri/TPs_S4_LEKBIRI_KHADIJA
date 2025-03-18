#ifndef MOVIE
#define MOVIE

#include <iostream>
#include <string>

using namespace std;

class Movie{
    private:
        string name;
        string rating;
        int watched;
    public:
        Movie(string val_name,string val_rating,int val_watched);

        void display();
        void increment_watched();

        string get_name();
        string get_rating();
        int get_watched();

        void set_name(string val);
        void set_rating(string r);
        void set_watched(int n);
        
        ~Movie();
};
    
#endif