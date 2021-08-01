#include <string>
#include <iostream>
using namespace std;
#include "Episode.h"
#include <fstream>
#include <limits>

Episode::Episode(int id, string title, int num, int temp, int cal, int rev){
    ID=id;
    Title=title;
    Num=num;
    Temp=temp;
    calVid=cal;
    reviews = rev;
    metaData = to_string(id)+","+title+","+to_string(num)+","+to_string(temp)+","+to_string(cal)+","+to_string(rev);
}

Episode::Episode(){
    ID = 0;
    Title = "";
    Num  = 0;
    Temp = 0;
    calVid = 0;
}

int Episode::getID(){
    return ID;
}

string Episode::getmetaData(){
    return metaData;
}
void Episode::rateVideo(int calificacion){
    reviews++;
    calVid = ((calVid)*(reviews-1) + calificacion)/reviews;
    metaData = to_string(ID)+","+Title+","+to_string(Num)+","+to_string(Temp)+","+to_string(calVid)+","+to_string(reviews);
}

void Episode::showData(){
    cout<<"Series ID: "<<ID<<endl;
    cout<<"Titulo: "<<Title<<endl;
    cout<<"Numero de espisodio: " <<Num<<endl;
    cout<<"Temporada: " <<Temp<<endl;
    cout<<"Calificacion: "<<calVid<<endl;
    cout<<"Reviews: "<<reviews<<endl;
}


Episode Episode::fromTxtLine(string line){
    string fields[6];
     int npos = 0;
     int token;
     string split = ",";

     for (int i = 0; i < 6; i++){
         token = line.find(split);
         fields[i] = line.substr(npos,token);
         line.erase(0, token + split.length());
     }

     Episode returnEpisode = Episode(stoi(fields[0]),fields[1],stoi(fields[2]),stoi(fields[3]),stoi(fields[4]),stoi(fields[5]));
     return returnEpisode;

}