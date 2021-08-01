#ifndef PELICULA_H
#define PELICULA_H

#include <string>
#include <iostream>
using namespace std;
#include "Video.h"



class Movie : public Video{
    public:
        Movie();
        Movie(int, string, string, int, int, int);
        void showData();
        void rateVideo(int);
        static Movie fromTxtLine(string);
    private:
        int duration;
        

};

#endif