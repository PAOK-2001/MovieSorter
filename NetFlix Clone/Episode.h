#ifndef EPISODE_H
#define EPISODE_H

#include <string>
#include <iostream>

using namespace std;

class Episode{
    private:
        int ID;
        string Title;
        string metaData;
        int Num;
        int Temp;
        int calVid;
        int reviews;
        
    public:
        Episode(int id, string title, int num, int temp, int cal, int rev);
        Episode();
        int getID();
        void rateVideo(int);
        string getmetaData();
        static Episode fromTxtLine(string);
        void showData();
        
};

#endif


