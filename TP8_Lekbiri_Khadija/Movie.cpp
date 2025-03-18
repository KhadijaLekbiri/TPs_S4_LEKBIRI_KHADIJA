#include <iostream>
#include <string>
#include "Movie.hpp"

using namespace std;


void Movie::increment_watched(){
    watched++;
}
void Movie::display(){
    cout<<name<<", "<<rating<<", "<<watched<<'\n'; 
}

string Movie::get_name(){
    return name;
}
string Movie::get_rating(){
    return rating;
}
int Movie::get_watched(){
    return watched;
}

void Movie::set_name(string val){
    name = val;
}
void Movie::set_rating(string r){
    rating = r;
}
void Movie::set_watched(int n){
    watched = n;
}
Movie::Movie(string val_name,string val_rating,int val_watched)
: name(val_name), rating(val_rating), watched(val_watched) {}
    
Movie::~Movie(){}
    