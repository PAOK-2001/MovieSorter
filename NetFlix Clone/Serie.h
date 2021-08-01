#ifndef SERIE_H
#define SERIE_H

#include <string>
#include <iostream>
using namespace std;
#include "Video.h"
#include "Episode.h"
#include <vector>

class Serie : public Video{
    public:
        Serie();
        Serie(int id, string name, string genero, int cali , int episodes, int seassons, int rev);
        void showData();
        void rateVideo(int );
        void rateEpisode(int, int);
        void addEpisode(Episode);
        void showEpisodes();
        static Serie fromTxtLine(string line);
        vector<Episode>SeriesEpisodes;

    private:
        int numEpisodes;
        int numSeassons;
        
};

#endif