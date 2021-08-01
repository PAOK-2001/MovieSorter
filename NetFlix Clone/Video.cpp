#include <string>
#include <iostream>
using namespace std;
#include "Video.h"

Video::Video(){
    Name = "";
    Genre  = "";
    calVid  = 0;
    ID = 0;
}

Video::Video(string name, string genero, int cali ,  int id, int rev){
    Name = name;
    Genre  = genero;
    calVid  = cali;
    ID = id;
    reviews = rev;

}

int Video::getID(){
    return ID;
}

void Video::rateVideo(int calificacion){
    calVid = (calVid + calificacion)/2;

}

void Video::showData(){
    cout<<"ID: "<<ID<<endl;
    cout<<"Nombre: "<<Name<<endl;
    cout<<"Genero: " <<Genre<<endl;
    cout<<"Calificación: " <<calVid<<endl;

}

string Video::getmetaData(){
    return metaData;
}

