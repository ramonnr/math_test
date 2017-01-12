
#include "untested_math.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void output_test_result(const char*, bool);
bool square_test(void);
bool triangle_area_test(void);
bool triangle_area2_test(void);
bool increment_test(void);
bool increment2_test(void);
bool increment3_test(void);

int main(){
  //seed pseudo random generator
  srand(time(NULL));

  //test square function
  output_test_result("square()",square_test());

  //test triangle_area function
  output_test_result("triangle_area()",triangle_area_test());

  //test triangle_area2 function
  output_test_result("triangle_area2()",triangle_area2_test());

  //test increment function
  output_test_result("increment()", increment_test());

  //test increment2 function
  output_test_result("increment2()", increment2_test());

  //test increment3 function
  output_test_result("increment3()", increment3_test());

}

//this function is only used to clean up the main function
void output_test_result(const char* str, bool result){
  if(result == true)printf("%s : pass\n",str);
  else printf("%s : failed\n",str);
}

bool square_test(void){
  bool result = true;
  //testing one edge case and two simple cases
  if(square(2) != 4) result = false;
  if(square(-1)!=1)  result = false;
  if(square(10)!=100)result = false;
  //run test on random input
  for(int i = 0; i < 10000; i++){
    int rnd = rand();
    if(square(rnd) != rnd*rnd) result = false;
    //a square can never be negative
    //this should fail since square retuns singed integer, should be unsigned
    //also no bounds checks, this will overflow
    if(square(rnd) < 0) result = false;
  }
  
  return result;
}