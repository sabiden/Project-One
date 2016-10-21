#include "linklistfxn.h"
#ifndef MY_TUNES

#define MY_TUNES


void add_song(song_node * d[26], char * a, char * s){
  int i = 0;
  while(strcmp(d[i]->artist, a) < 0){
    i = i + 1;
  }
  d[i-1] = insert_order(d[i-1], a, s);;
}
    
void delete_song(song_node * d[26], char * s){
  int i = 0;
  while(i < 26){
    d[i] = remove_song(d[i],s);
    i = i + 1;
  }  
}


song_node * search_song(song_node * d[26], char * s){
  song_node * retNode = NULL;
  int i = 0;
  while(retNode == NULL && i < 26){
    retNode = find_song(d[i],s);
    i = i + 1;
  }
  if(retNode == NULL){
    printf("No such song found\n");
    return d[0];
  }
  else{
    return retNode;
  }
}

song_node * search_artist(song_node * d[26], char * a){
  song_node * retNode = NULL;
  int i = 0;
  while(strcmp(d[i]->artist, a) < 0){
    i = i + 1;
  }
  retNode = find_artist(d[i-1],a);
  if(retNode == NULL){
    printf("No such artist found\n");
    return d[0];
  }
  else{
    return retNode;
  }
}

void print_indv_entry(song_node * d[26], char * l){
  int i = 0;
  while(i < 26 && strcmp(d[i]->artist, l) != 0){
    i++;
  }
  print_songNodes(d[i]->next);
}

void print_artist_songs(song_node * d[26], char * a){
  int i = 0;
  while(i < 26 && strcmp(d[i]->artist, a) < 0){
    i++;
  }
  song_node * x = d[i-1];
  while(x != NULL){
    if(strcmp(x->artist,a) == 0){
      printf("%s - %s\n",x->artist, x->name);
    }
    x = x->next;
  }
}

void shuffle(song_node * d[26], int len){
  while(len > 0){
    int x = (rand() % 26);
    while(d[x] -> next == NULL){
      x = (rand() % 26);
    }
    song_node * j = find_random(d[x]->next);
    printf("%s - %s  ",j->artist, j->name);
    len--;
    srand(time(NULL) * len);
  }
  printf("\n");
}


void print_library(song_node * d[26]){
  int i = 0;
  while(i < 26){
    if(d[i] != NULL){
      if((d[i]->next) != NULL){
	printf("=== %s ===\n", d[i]->artist);
	print_songNodes(d[i]->next);
	
      }
    }
     i++;
  }
}

void free_library(song_node * d[26]){
  int i = 0;
  while(i < 26){
    d[i] = free_nodes(d[i]);
    i++;
  }
}

/*
void main(){
  srand(time(NULL));
  song_node *table[26];
  table[0] = insert_first(table[0], "a", "a");
  table[1] = insert_first(table[0], "b", "b");
  table[2] = insert_first(table[0], "c", "c");
  table[3] = insert_first(table[0], "d", "d");
  table[4] = insert_first(table[0], "e", "e");
  table[5] = insert_first(table[0], "f", "f");
  table[6] = insert_first(table[0], "g", "g");
  table[7] = insert_first(table[0], "h", "h");
  table[8] = insert_first(table[0], "i", "i");
  table[9] = insert_first(table[0], "j", "j");
  table[10] = insert_first(table[0], "k", "k");
  table[11] = insert_first(table[0], "l", "l");
  table[12] = insert_first(table[0], "m", "m");
  table[13] = insert_first(table[0], "n", "n");
  table[14] = insert_first(table[0], "o", "o");
  table[15] = insert_first(table[0], "p", "p");
  table[16] = insert_first(table[0], "q", "q");
  table[17] = insert_first(table[0], "r", "r");
  table[18] = insert_first(table[0], "s", "s");
  table[19] = insert_first(table[0], "t", "t");
  table[20] = insert_first(table[0], "u", "u");
  table[21] = insert_first(table[0], "v", "v");
  table[22] = insert_first(table[0], "w", "w");
  table[23] = insert_first(table[0], "x", "x");
  table[24] = insert_first(table[0], "y", "y");
  table[25] = insert_first(table[0], "z", "z");
  printf("PRINTING WHOLE LIBRARY\n\n");
  print_library(table);
  
  printf("\n\n");

  printf("Adding a couple songs\n\n");
  add_song(table, "maroon five", "one more night");
  add_song(table, "gcc", "i hate you");
  add_song(table, "maroon five", "payphone");
  add_song(table, "gcc", "you suck");
  add_song(table, "avicci", "wake me up");
  add_song(table, "acdc", "lightning");


  print_library(table);
  
  printf("\n\n");
  printf("DELETING wake me up by avvici\n\n");
  delete_song(table, "wake me up");

  print_library(table);
  
  printf("\n\n");
  printf("DELETING NONEXISTANT SONG\n\n");
  delete_song(table, "blagh");

  print_library(table);

  printf("Searching for 'one more night':\n\n");
  song_node * x = search_song(table,"one more night");
  printf("%s - %s\n\n",x->artist, x->name);
  printf("Searching for 'three more nights':\n\n");
  x = search_song(table,"three more nights");

  printf("\n\nSearching for artist 'gcc':\n\n");
  x = search_artist(table,"gcc");
  printf("%s - %s\n\n",x->artist, x->name);
  printf("Searching for artist 'gcc is the best':\n\n");
  x = search_artist(table,"gcc is the best");

  printf("\n\nListing all entries under 'm':\n\n");
  print_indv_entry(table,"m");
  printf("adding more m artists:\n\n");
  add_song(table, "micheal jackson", "beat it");
  add_song(table, "micheal jackson", "man in the mirror");
  print_indv_entry(table,"m");

  
  printf("\n\nadding more mj songs :\n\n");
  add_song(table, "micheal jackson", "thriller");
  add_song(table, "micheal jackson", "billie jean");
  printf("Printing all of micheal jacksons songs:\n\n");
  print_artist_songs(table,"micheal jackson");

  shuffle(table, 5);
}
*/
#endif

