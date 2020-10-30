#include <stdlib.h>
#include <stdio.h>

#define NAMELEN 8
#define NSCORES 10


typedef struct {
  char name[NAMELEN+1];
  int score;
} hsentry;

hsentry highscores[NSCORES];

int main() {
  FILE *file = fopen("highscores.txt", "rb");
  for (int i=0; i<10; i++) {
    //int buffsize=128;
    //char buffer[128];
    //fgets(buffer, buffsize, file);
    //printf("%s", buffer);
    fscanf(file, "%8c %i\n", highscores[i].name, &highscores[i].score);
  }
  return 0;
}
