#include <stdlib.h>
#include "linklistfxn.h"
#include <string.h>


song_node * insert_front(song_node * list, char *song, char *artist){
  song_node * newNode = (song_node *) malloc(sizeof(song_node));
  newNode->name = song;
  newNode->artist = artist;
  newNode->next = list;
  return newNode;
}

song_node * insert_order(song_node * list, char * song, char * artist){

  song_node * retNode = list;
  song_node * prevNode;

  while(strcmp(list.artist, artist) < 0){
    prevNode = list;
    list = list.next;
  }
  
  while(strcmp(list.artist, artist) == 0 && strcmp(list.name, song)){
    prevNode = list;
    list = list.next;
  }
  
  song_node * newNode = (song_node *) malloc(sizeof(song_node));
  newNode->name = song;
  newNode->artist = artist;
  newNode->next = list;
  prevNode->next = newNode;

  return retNode;
  
}

