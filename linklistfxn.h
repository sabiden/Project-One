#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;


song_node * insert_front(song_node * list, char * s, char * a){
  song_node * newNode = (song_node *) malloc(sizeof(song_node));
  strcpy(newNode->name, s);
  strcpy(newNode->artist, a);
  newNode->next = list;
  return newNode;
}

song_node * insert_order(song_node * list, char * s, char * a){
  song_node * retNode = list;
  song_node * prevNode;

  if(list == NULL){return insert_front(list,s,a);}

  while(strcmp(list->artist, a) < 0){
    prevNode = list;
    list = list->next;
  }
  
  while(strcmp(list->artist, a) == 0 && strcmp(list->name, s)){
    prevNode = list;
    list = list->next;
  }
  
  song_node * newNode = (song_node *) malloc(sizeof(song_node));
  strcpy(newNode->name, s);
  strcpy(newNode->artist, a);
  newNode->next = list;
  prevNode->next = newNode;

  return retNode;
  
}

void print_songNodes(song_node * list){
  printf("CALLED");
  while(list != NULL){
    printf("%s - %s\n",list->artist, list->name);
    list = (list->next);
  }
  printf("\n");
  return;
}

song_node * find_song(song_node *  list, char song[]);

song_node * find_artist(song_node * list, char artist[]);

song_node * find_random(song_node *list);

song_node * remove_song(song_node * list, char song[] );

void free_node(song_node * list){
  while(list != NULL){
    song_node * temp = list;
    free(list);
    list = temp->next;
  }
  return;
}

void main(){
  song_node * A = (song_node *) malloc(sizeof(song_node));
  A = NULL;
  A = insert_order(A, "Always", "Ajax");
  printf("MADE IT");
  print_songNodes(A);
}

