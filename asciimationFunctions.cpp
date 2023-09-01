#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

List<pair<int, string>>* loadMovie(string filename) {
  ifstream myFile;
  string data;

  myFile.open(filename);
  if(!myFile.is_open()) {
    throw runtime_error("file " + filename + " failed to open ");
  }
  getline(myFile, data);

  List<pair<int, string>>* mymovie = new LinkedList<pair<int, string>>();

  while (!myFile.eof()) {
    pair<int,string> p1;
    p1.first = stoi(data);
    p1.second = "";
    for (int i=0; i<13; i++){
      getline(myFile, data);
      p1.second += data + "\n";
    }

    mymovie->insertLast(p1);
    getline(myFile, data);
  }
  return mymovie;
}

void playMovie(List<pair<int, string>>* list) {
  for(int i=0; i<list->getSize(); i++){
      cout << list->get(i).second << endl;
      usleep((1000000/15) * list->get(i).first);
      system("clear");
  }
}
