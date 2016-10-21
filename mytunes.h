#include "linklistfxn.h"

void add_song(song_node * d[26], char * a, char * s);

void delete_song(song_node * d[26], char * s);

song_node * search_song(song_node * d[26], char * s);

song_node * search_artist(song_node * d[26], char * a);

void print_indv_entry(song_node * d[26], char * l);

void shuffle(song_node * d[26], int len);

void print_library(song_node * d[26]);
