#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node * insert_first(song_node * list, char * a, char * s);

song_node * insert_front(song_node * list, char * a, char * s);

song_node * insert_order(song_node * list, char * a, char * s);

void print_songNodes(song_node * list);

song_node * find_song(song_node *  list, char song[]);

song_node * find_artist(song_node * list, char artist[]);

song_node * find_random(song_node *list);

song_node * remove_song(song_node * list, char song[] );

void free_node(song_node * list);
