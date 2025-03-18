#ifndef MOVIES
#define MOVIES

#include <iostream>
#include <string>
#include <vector>
#include "Movie.hpp"

using namespace std;

class Movies{
    public:
        vector <Movie> my_movies;
        Movies(/* args */);
        void display();
        
        bool increment_watched(const string &name);

        bool add_movie(string &name, string &rating, int watched);

        ~Movies();
};

#endif 