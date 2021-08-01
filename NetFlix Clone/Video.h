#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>

using namespace std;

class Video{
    protected:
        string Name;
        string Genre;
        int ID;
        int calVid;
        string metaData;
        int reviews;

    public:
        Video();
        Video(string name, string genero, int cali ,  int id, int rev);
        virtual void rateVideo(int calificacion);
        int getID();
        string getmetaData();
        virtual void showData();
};

#endif