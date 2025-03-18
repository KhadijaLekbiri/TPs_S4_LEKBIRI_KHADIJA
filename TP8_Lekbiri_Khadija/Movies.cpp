#include <iostream>
#include <string>
#include "Movies.hpp"

using namespace std;


void Movies::display(){
    if (my_movies.empty()){
        cout<<"Désolé, aucun film à afficher \n\n";
        return;
    }
    cout<<"\n=================================== \n";
    for (auto film : my_movies){
        film.display();}
    cout<<"=================================== \n\n";
}

bool Movies::increment_watched(const string &name){
    for (auto &film : my_movies){
        if (film.get_name() == name){
            film.increment_watched();
            return true;
        }
    }
    return false;
}

bool Movies::add_movie(string &name, string &rating, int watched){
    for (auto film: my_movies){
        if (film.get_name() == name){
            return false;
        }
    }
    Movie nouveau = Movie(name,rating,watched);
    my_movies.push_back(nouveau);
    return true;
}

Movies::Movies(/* args */){
}

Movies::~Movies(){
}