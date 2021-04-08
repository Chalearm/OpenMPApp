#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "check.h"
#include "util.h"
#include "problem.h"
#include "solution.h"

static problem_t  p;
static solution_t s;

int main(int argc, char* argv[])
{
  int score;
  float ppp = 0.0;  
  clock_t clock1;
  clock_t clock2;
const int loopCount = 2;
  if (argc != 3) {
    fprintf(stderr, "usage: %s problem solution\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  measureTime(0,&clock1,"");
  for(int i = 0;i< loopCount;i++)
  {

 measureTime(0,&clock2,"");
  CHECK(problem_read(argv[1], &p) == 0);
  CHECK(solution_read(argv[2], &s, &p) == 0);

  CHECK(solution_check(&s, &p) == 0); 
  score = solution_score(&s, &p); 
  //fprintf(stderr, "Score %d\n", score);

  // Write the score file
  util_write_score(argv[2], score);


  fprintf(stderr,"Round #%d score:%d ",i+1,score);
  measureTime(1,&clock2," ");

  }
  ppp = measureTime(2,&clock1,"");
  printf("Total time : %4.4f  , avg:%4.4f\n",ppp,ppp/(float)loopCount);
  return(0);
}
