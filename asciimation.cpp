#include <iostream>
#include <string>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

int main(int argc, char** argv) {
  if(argc == 2 || argc == 3){
    if(argc == 2){
      List<pair<int, string>>* mymovie = loadMovie(argv[1]);
      playMovie(mymovie);
      delete mymovie;
    }
    else{
      if((string)argv[1] == "--reverse"){
        List<pair<int, string>>* mymovie = loadMovie(argv[2]);
        List<pair<int, string>>* reverseMovie = new LinkedList<pair<int, string>>();
        for(int i=0; i<mymovie->getSize(); i++){
          reverseMovie->insertFirst(mymovie->get(i));
        }
        playMovie(reverseMovie);
        delete mymovie;
        delete reverseMovie;
      }
      else{
        cout << "Invalid command" << endl;
        cout << "usage2: ./asciimation --reverse filename" << endl;
      }
    }
  }
  else{
    cout << "Invalid command" << endl;
    cout << "usage1: ./asciimation filename" << endl;
    cout << "usage2: ./asciimation --reverse filename" << endl;
  }

    return 0;
}
