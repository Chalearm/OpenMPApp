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
  float ppp = 0.0; 
  clock_t clock1;
  clock_t clock2;
  clock_t clock3;
const int loopCount = 4;
  if (argc != 3) {
    fprintf(stderr, "usage: %s problem solution\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  measureTime(0,&clock2,"");
  for(int i = 0;i< loopCount;i++)
  {
       //  int countStreet[100000];
//     int factorSlot[100000][5];

  measureTime(0,&clock3,"");
    memset(countStreet,0,sizeof(countStreet));
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


  measureTime(1,&clock3,"a loop time: ");

  }
  ppp = measureTime(1,&clock2,"All time is ");
  printf("Total time : %4.4f  , avg:%4.4f\n",ppp,ppp/(float)loopCount);
  return(0);
}
