#include "mytunes.h"


void main(){
  printf("=========LINKLIST FUNCTIONS============\n\n\n");
  
  song_node * A = (song_node *) malloc(sizeof(song_node));
  A = NULL;

  printf("Testing ADD SONG function and PRINT LIST function\n\n");
  A = insert_order(A, "ajax", "always");
  print_songNodes(A);
  A = insert_order(A, "apox", "beyond me");
  print_songNodes(A);
  A = insert_order(A, "apox", "you hate me");
  print_songNodes(A);
  A = insert_order(A, "abe", "sad song");
  print_songNodes(A);

  printf("\n\nTesting FIND SONG function using 'always'\n\n");
  song_node * test = find_song(A, "always");
  printf("%s - %s\n",test->artist, test->name);

  printf("\n\nTesting FIND ARTIST function using 'apox'\n\n");
  song_node * test2 = find_artist(A, "apox");
  printf("%s - %s\n\n",test2->artist, test2->name);

  printf("\n\nTesting REMOVE SONG function\n\n");
  print_songNodes(A);
  printf("Removing 'always'\n");
  A = remove_song(A, "always");
  print_songNodes(A);
  printf("Removing 'sad song'\n");
  A = remove_song(A, "sad song");
  print_songNodes(A);
  printf("Removing 'you hate me'\n");
  A = remove_song(A, "you hate me");
  print_songNodes(A);

  printf("\n\nAdding more songs:\n\n");
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

  printf("Testing FIND RANDOM function:\n\n");
  song_node * test3 = find_random(A);
  printf("%s - %s\n\n",test3->artist, test3->name);


  printf("\n\nTesting FREE NODES function:\n\n");
  A = free_nodes(A);
  print_songNodes(A);

  printf("\n\n=========LIBRARY FUNCTIONS============\n\n\n");
  
  srand(time(NULL));

  printf("First, we shall begin testing by intializing a library ");
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
  printf("and then print it: \n");
  printf("INTIALIZING AND PRINTING WHOLE LIBRARY\n\n");
  print_library(table);

  printf("Hmmm, nothing printed? Well thats cuz there are no songs and our library is empty\nLets add some songs: \n\n");
  
  printf("Adding a couple songs using the ADD SONG function\n\n");
  add_song(table, "maroon five", "one more night");
  add_song(table, "gcc", "i hate you");
  add_song(table, "maroon five", "payphone");
  add_song(table, "gcc", "you suck");
  add_song(table, "avicci", "wake me up");
  add_song(table, "acdc", "lightning");
  printf("Now we can print the library again:\n\n");

  print_library(table);
  
  printf("\n\nNow can can try deleting some using the DELETE SONG function:\n");
  printf("DELETING wake me up by avvici\n\n");
  delete_song(table, "wake me up");

  print_library(table);

  printf("\nNothing happens when you delete a noexistant song:");
  printf("\n\n");
  printf("DELETING NONEXISTANT SONG\n\n");
  delete_song(table, "blagh");

  print_library(table);

  printf("\nNow we can search for some songs using the SEARCH SONG function\nSearching for 'one more night':\n\n");
  song_node * x = search_song(table,"one more night");
  printf("%s - %s\n\n",x->artist, x->name);
  printf("And also nonexistsant ones\nSearching for 'three more nights':\n\n");
  x = search_song(table,"three more nights");

  printf("\n\nWe can also search for artists using the SEARCH ARTIST fucntion\nSearching for artist 'gcc':\n\n");
  x = search_artist(table,"gcc");
  printf("%s - %s\n\n",x->artist, x->name);
  printf("And also nonexistsant ones\nSearching for artist 'gcc is the best':\n\n");
  x = search_artist(table,"gcc is the best");

  printf("\n\nNext we can print the under a given letter using the LIST INDV LETTER function\nListing all entries under 'm':\n\n");
  print_indv_entry(table,"m");
  printf("Adding more m artists to prove it is true :\n\n");
  add_song(table, "micheal jackson", "beat it");
  add_song(table, "micheal jackson", "man in the mirror");
  print_indv_entry(table,"m");

  
  printf("\n\nJust for fun adding more mj songs :\n\n");
  add_song(table, "micheal jackson", "thriller");
  add_song(table, "micheal jackson", "billie jean");
  printf("Printing all of micheal jacksons songs using the PRINT ARTIST SONG function:\n\n");
  print_artist_songs(table,"micheal jackson");

  printf("\n\nNow can can create a random playlist using shuffle, lets go with five songs: \n\n");
  shuffle(table, 5);

  printf("\n\nLastly we can free up all the nodes and make the library disappear\n\n");
  free_library(table);
  printf("Lets try printing the library again:\n\n");
  print_library(table);
  printf("Nothing, just what we wanted!!!\n\n\n");
	 
	 

}
