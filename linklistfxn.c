#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;





song_node * insert_front(song_node * list, char * a, char * s){
  song_node * newNode = (song_node *) malloc(sizeof(song_node));
  strcpy(newNode->name, s);
  strcpy(newNode->artist, a);
  newNode->next = list;
  return newNode;
}




song_node * insert_order(song_node * list, char * a, char * s){
  song_node * retNode = list;
  song_node * prevNode;

  //For the songs that go in the begginning
  if(list == NULL || strcmp(list->artist, a) > 0){return insert_front(list,a,s);}

  //Checking location based on artist
  while(list != NULL && strcmp(list->artist, a) < 0 ){
    prevNode = list;
    list = list->next;
  }

  //Checking location based on song name
  if( list != NULL && strcmp(list->artist, a) == 0){
    while(list != NULL && strcmp(list->name, s) < 0 ){
      prevNode = list;
      list = list->next;
    }
  }
  
  //Adding to location
  song_node * newNode = (song_node *) malloc(sizeof(song_node));
  strcpy(newNode->name, s);
  strcpy(newNode->artist, a);
  newNode->next = list;
  prevNode->next = newNode;
  
  return retNode;
  
}




void print_songNodes(song_node * list){
  if(list == NULL){
    printf("EMPTY ALBUM");
  }
  while(list != NULL){
    printf("%s - %s\n",list->artist, list->name);
    list = (list->next);
  }
  printf("\n");
  return;
}




song_node * find_song(song_node *  list, char * s){
  while(list != NULL && strcmp(list->name, s) != 0 ){
      list = list->next;
    }
  return list;
}





song_node * find_artist(song_node * list, char * a){
  while(list != NULL && strcmp(list->artist, a) < 0 ){
    list = list->next;
  }
  return list;
}
  




song_node * find_random(song_node *list){
  song_node * top = list;
  srand(time(NULL));
  int counter = (rand() % 100);
  while (counter > 0){
    if(list == NULL){
      list = top;
    }
    list = list->next;
    counter --;
  }
  if(list == NULL){
    return top;
  }
  return list;
}



song_node * remove_song(song_node * list, char * s ){
  song_node * retNode = list;
  song_node * prevNode = NULL;
  while(list != NULL && strcmp(list->name, s) != 0 ){
    prevNode = list;
    list = list->next;
  }
  if(list == NULL){
    return retNode;
  }
  if(prevNode == NULL){
    retNode = list->next;
    free(list);
  }
  else{
    prevNode->next = list->next;
    free(list);
  }
  return retNode;
}


 song_node * free_nodes(song_node * list){
  while(list != NULL){
    song_node * temp = list->next;
    free(list);
    list = temp;
  }
  return NULL;
}



void main(){
  song_node * A = (song_node *) malloc(sizeof(song_node));
  A = NULL;
  A = insert_order(A, "ajax", "always");
  print_songNodes(A);
  A = insert_order(A, "apox", "beyond me");
  print_songNodes(A);
  A = insert_order(A, "apox", "you hate me");
  print_songNodes(A);
  A = insert_order(A, "abe", "sad song");
  print_songNodes(A);
  song_node * test = find_song(A, "always");
  printf("%s - %s\n",test->artist, test->name);
  
  song_node * test2 = find_artist(A, "apox");
  printf("%s - %s\n\n",test2->artist, test2->name);
  
  print_songNodes(A);
  A = remove_song(A, "always");
  print_songNodes(A);
  A = remove_song(A, "sad song");
  print_songNodes(A);
  A = remove_song(A, "you hate me");
  print_songNodes(A);

  A = insert_order(A, "abe", "sad song");
  A = insert_order(A, "apox", "you hate me");
  A = insert_order(A, "ajax", "always");
  A = insert_order(A, "bae", "super sad song");
  A = insert_order(A, "pox", "why do you hate me");
  A = insert_order(A, "nax", "always hated you");
  A = insert_order(A, "dec", "saddest song");
  A = insert_order(A, "rux", "you love me?");
  A = insert_order(A, "rux", "and always");
  print_songNodes(A);

  song_node * test3 = find_random(A);
  printf("%s - %s\n\n",test3->artist, test3->name);

  //A = free_nodes(A);
  //print_songNodes(A);
}

