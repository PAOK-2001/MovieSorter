#include <string>
#include <iostream>
using namespace std;
#include "Serie.h"

Serie::Serie(int id, string name, string genero, int cali , int episodes, int seassons, int rev):Video(name,genero,cali,id, rev){
    numEpisodes = episodes;
    numSeassons = seassons;
    metaData = to_string(id)+","+name+","+genero+","+to_string(cali)+","+to_string(episodes)+","+to_string(seassons)+","+to_string(rev);
}

Serie::Serie():Video(){
    numEpisodes = 0;
    numSeassons = 0;
}

void Serie::showData(){
    cout<<"ID: "<<ID<<endl;
    cout<<"Nombre: "<<Name<<endl;
    cout<<"Genero: " <<Genre<<endl;
    cout<<"Episodios: " <<numEpisodes<<endl;
    cout<<"Temporadas: "<<numSeassons<<endl;
    cout<<"Calificación: " <<calVid<<endl;
    cout<<"Reviews: "<<reviews<<endl;

}

void Serie::rateVideo(int cal){
    reviews++;
    calVid = ((calVid)*(reviews-1) + cal)/reviews;
    metaData = to_string(ID)+","+Name+","+Genre+","+to_string(calVid)+","+to_string(numEpisodes)+","+to_string(numSeassons)+","+to_string(reviews);
}

void Serie::addEpisode(Episode epi){
    SeriesEpisodes.push_back(epi);
}

void Serie::showEpisodes(){
     for (int i = 0; i < SeriesEpisodes.size(); i++){
            SeriesEpisodes[i].showData();
            cout<<endl;
        }
}

void Serie::rateEpisode(int num, int cal){
    SeriesEpisodes[num].rateVideo(cal);
    
}
Serie Serie::fromTxtLine(string line){
    string fields[7];
    int npos = 0;
    int token;
    string split = ",";

    for (int i = 0; i < 7; i++){
        token = line.find(split);
        fields[i] = line.substr(npos,token);
        line.erase(0, token + split.length());
    }

    Serie returnSeries = Serie(stoi(fields[0]),fields[1],fields[2], stoi(fields[3]), stoi(fields[4]),stoi(fields[5]), stoi(fields[6]));
    return returnSeries;

}