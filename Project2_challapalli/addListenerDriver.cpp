// CSCI 1300 Fall 2021
// Author: Kash Challapalli
// Recitation: 213 - Jerry Gammie
// Project 2 - Problem #9

#include "Listener.h"
#include "Song.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string toLower(string gen){
    string low = "";
    for (int i = 0; i<gen.length(); i++){
        if (gen[i]<97){
            low += gen[i]+32;
        }

        else {
            low += gen[i];
        }
    }
    return low;
}

int addListener(string listenerName, Listener listeners[], int numSongs = 50, int numListenersStored, int listenersArrSize = 100){
    if (listenerName == ""){
        return -3;
    }
    if (numListenersStored >= listenersArrSize){
        return -1;
    }
    
    for (int i = 0; i<listenersArrSize; i++){
        if (toLower(listeners[i].getListenerName()) == toLower(listenerName)){
            return -2;
        }
            

    }
    Listener li = Listener();
    li.setListenerName(listenerName); 
    listeners[numListenersStored] = li;
    return numListenersStored+1;
    
    
}

int main(){
    Listener listeners[2];
    int listenerArrSize = 2;
    int numSongs  = 5;

    listeners[0].setListenerName("Ninja");

    // Add 5 listens by the user "Ninja"
    for(int i=0; i<numSongs; i++) {
        listeners[0].setPlayCountAt(i, i);
    }

    int numListenersStored = 1;

    cout<<addListener("Knuth", listeners, numSongs, numListenersStored, listenerArrSize)<<endl;
}