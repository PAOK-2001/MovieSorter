
/* Alumno: Pablo Agustín Ortega Kral
Matrícula: A0034464
Alumno: Ana Lucía Cárdenas Pérez
Matrícula: A01284090 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits>
#include "Movie.h"
#include "Serie.h"
#include "Episode.h"
#include <locale.h>

using namespace std;

vector<Movie>MovieList;
vector<Serie>SerieList;
vector<Episode>EpisodeList;

bool isNumber(int a){
 try{
     if (!std::cin.good()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw 1;
    }
    
    else{
        return true;
    }
 }
 catch(int){
     cout<<"Valor Invalido"<<endl;
     return false;
 }
 
}

bool withinLimit(int low, int high, int c){
    try{
        if (low>c||high<c){
            throw 1;
        }

        else{            
            return true;
        }
        
    }
    catch(int){
        std::cout<<"Valor Invalido"<<endl;
        return false;
    }

}


int main() {
    setlocale(LC_ALL, "spanish");
    string line;
    ifstream Movies;
    ifstream Series;
    ifstream Episodes;
    ofstream Series_Write;
    ofstream Movies_Write;
    ofstream Episodes_Write;
    bool menu = true;
    int opcion;
    int cal;
    int id;
    int epi;

    Movies.open("movies.txt");
    Series.open("series.txt");
    Episodes.open("episodes.txt");
    
    if (!Movies||!Series||!Episodes) {
        std::cout << "Unable to open file";
        exit(1); // terminate with error
    }

     while(Movies.good()){
        getline(Movies, line);
        MovieList.push_back(Movie::fromTxtLine(line));
    }

    while (Series.good()){
        getline(Series,line);
        SerieList.push_back(Serie::fromTxtLine(line));
    }
    
    while (Episodes.good()){
        getline(Episodes,line);
        EpisodeList.push_back(Episode::fromTxtLine(line));
    }
    
    Episodes.close();
    Series.close();
    Movies.close();


    for (int i = 0; i < SerieList.size() ; i++){
        for (int j = 0; j < EpisodeList.size(); j++)
        {
            if (SerieList[i].getID() == EpisodeList[j].getID()){
                SerieList[i].addEpisode(EpisodeList[j]);
            }   
        }
    }
    
    std::cout<<"Bienvenido al categorizador de Video"<<endl;

    do {
        std::cout << "Seleccione una opcion.\n" << "\n0. Salir\n" << "1. Mostrar Peliculas\n" << "2. Mostrar Serie\n" << "3. Califica Pelicula\n"<< "4. Califica Serie\n"<< "5. Ver Episodios\n"<< "6. Califica Episodio\n"<< endl;
        std::cin >> opcion;
        while (!withinLimit(0,6,opcion)||!isNumber(opcion)){
            std::cin >> opcion;
        }
        switch (opcion){
        case 0:
            menu = false;
            Movies_Write.open("movies.txt");
            Series_Write.open("series.txt");
            Episodes_Write.open("episodes.txt");

            for (int i = 0; i < MovieList.size(); i++){
                if (i == MovieList.size()-1){
                    Movies_Write << MovieList[i].getmetaData();
                }
                else{
                    Movies_Write << MovieList[i].getmetaData() << endl;
                }   
            }

            for (int i = 0; i < SerieList.size(); i++){
                if (i == SerieList.size()-1){
                    Series_Write << SerieList[i].getmetaData();
                }
                else{
                    Series_Write << SerieList[i].getmetaData() << endl;
                }
            }

            
            for (int i = 0; i < SerieList.size(); i++){
                for (int j = 0; j < SerieList[i].SeriesEpisodes.size(); j++)
                {
                    if (i == SerieList.size()-1){
                    Episodes_Write << SerieList[i].SeriesEpisodes[j].getmetaData();
                    }
                    else{
                        Episodes_Write << SerieList[i].SeriesEpisodes[j].getmetaData()<<endl;
                    }
                }
                
            }
            
            Episodes_Write.close();
            Series_Write.close();
            Movies_Write.close(); 
            break;

        case 1:
            std::cout<<"---Peliculas---"<<endl;
            for (int i = 0; i < MovieList.size(); i++){
                MovieList[i].showData();
                std::cout<<endl;
            }
            break;

        case 2:
            std::cout<<"---Series---"<<endl;
            for (int i = 0; i < SerieList.size(); i++){
                SerieList[i].showData();
                std::cout<<endl;
            }
            break;
        case 3:
            
            std::cout<<"---Películas---"<<endl;
            for (int i = 0; i < MovieList.size(); i++){
                    MovieList[i].showData();
                    std::cout<<endl;
                }
            std::cout<<"Ingresa el ID de la pelicula que quieres calificar: ";
            std::cin >>id;
            while (!withinLimit(0,(MovieList.size()-1),id)||!isNumber(id)){
                std::cin >> id;
            }
            std::cout<<endl<<"Ingresa calificación: ";
            std::cin >>cal;
            while (!withinLimit(0,5,cal)||!isNumber(cal)){
                std::cin >>cal;
            }
            MovieList[id].rateVideo(cal);

            break;
         case 4:
            
            std::cout<<"---Series---"<<endl;
            for (int i = 0; i < SerieList.size(); i++){
                    SerieList[i].showData();
                    std::cout<<endl;
                }
            std::cout<<"Ingresa el ID de la serie que quieres calificar: ";
            std::cin >>id;
            while (!withinLimit(0,(SerieList.size()-1),id)||!isNumber(id)){
                std::cin >> id;
            }
            std::cout<<endl<<"Ingresa calificación: ";
            std::cin >>cal;
            while (!withinLimit(0,5,cal)||!isNumber(cal)){
                std::cin >>cal;
            }
            SerieList[id].rateVideo(cal);

            break;
        case 5:
            std::cout<<"---Series---"<<endl;
            for (int i = 0; i < SerieList.size(); i++){
                SerieList[i].showData();
                std::cout<<endl;
            }
            std::cout<<"Ingresa el ID de la serie cuyos episodios quieres ver: ";
            std::cin >>id;
            while (!withinLimit(0,(SerieList.size()-1),id)||!isNumber(id)){
                std::cin >> id;
            }
            std::cout<<"---Episodios---"<<endl;
            SerieList[id].showEpisodes();
            break;
        case 6:
            for (int i = 0; i < SerieList.size(); i++){
                SerieList[i].showData();
                std::cout<<endl;
            }
            std::cout<<"Ingresa el ID de la serie cuyos episodios quieres calificar: ";
            std::cin >>id;
            while (!withinLimit(0,(SerieList.size()-1),id)||!isNumber(id)){
                std::cin >> id;
            }
            std::cout<<endl<<"---Episodios---";
            SerieList[id].showEpisodes();
            std::cout<<"Ingresa el episodio a calificar: ";
            std::cin >>epi;
            while (!withinLimit(0,(SerieList[id].SeriesEpisodes.size()),epi)||!isNumber(id)){
                std::cin >> epi;
            }
            epi=epi-1;
            std::cout<<endl<<"Ingresa calificación: ";
            std::cin >>cal;
            while (!withinLimit(0,5,cal)||!isNumber(cal)){
                std::cin >>cal;
            }
            SerieList[id].rateEpisode(epi, cal);

            break;
        default:
            break;
        }
    }while (menu);

}