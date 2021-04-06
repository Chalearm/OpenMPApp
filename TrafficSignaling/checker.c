#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "check.h"
#include "util.h"
#include "problem.h"
#include "solution.h"

static problem_t  p;
static solution_t s;
/*
void measureTime(const int startOrStop,const char *str)
{
    static clock_t referenceTime;

    if (startOrStop == 0)
    {
      referenceTime = clock();
    }
    else
    {
      float currentTime = ((float)(clock()-referenceTime))/CLOCKS_PER_SEC;
      printf("%s time count: %3.2f \n",str,currentTime);
    }
}*/

int main(int argc, char* argv[])
{
  int score; 
  clock_t clock1;

  if (argc != 3) {
    fprintf(stderr, "usage: %s problem solution\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  measureTime(0,&clock1,"");
  CHECK(problem_read(argv[1], &p) == 0);
  measureTime(1,&clock1,"problem read ");
  

  measureTime(0,&clock1,"");
  CHECK(solution_read(argv[2], &s, &p) == 0);
  measureTime(1,&clock1,"solution_read ");

  measureTime(0,&clock1,"");
  CHECK(solution_check(&s, &p) == 0);
  measureTime(1,&clock1,"solution_check ");

 // measureTime(0,"");
  score = solution_score(&s, &p);
  //measureTime(1,"solution_score ");
  printf("score : %d \n",score);

  // Write the score file
  util_write_score(argv[2], score);

  return(0);
}
