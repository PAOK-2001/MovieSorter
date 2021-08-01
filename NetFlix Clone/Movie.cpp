#include <string>
#include <iostream>
using namespace std;
#include "Movie.h"
#include <fstream>
#include <limits>

Movie::Movie(int  id, string name, string gen, int cali, int dura, int rev):Video(name,gen,cali,id, rev){
    duration = dura;
    metaData = to_string(id)+","+name+","+gen+","+to_string(cali)+","+to_string(dura)+","+to_string(rev);

}

Movie::Movie(){
    duration = 0;

}

void Movie::rateVideo(int cal){
    reviews++;
    calVid = ((calVid)*(reviews-1) + cal)/reviews;
    metaData = to_string(ID)+","+Name+","+Genre+","+to_string(calVid)+","+to_string(duration)+","+to_string(reviews);

}


void Movie::showData(){
    cout<<"ID: "<<ID<<endl;
    cout<<"Nombre: "<<Name<<endl;
    cout<<"Genero: " <<Genre<<endl;
    cout<<"Calificación: " <<calVid<<endl;
    cout<<"Duración: "<<duration<<endl;
    cout<<"Reviews: "<<reviews<<endl;
}

Movie Movie::fromTxtLine(string line) {
     string fields[6];
     int npos = 0;
     int token;
     string split = ",";

     for (int i = 0; i < 6; i++){
         token = line.find(split);
         fields[i] = line.substr(npos,token);
         line.erase(0, token + split.length());
     }


    Movie returnMovie = Movie(stoi(fields[0]), fields[1], fields[2],stoi(fields[3]),stoi(fields[4]),stoi(fields[5]));
    return returnMovie;
}

