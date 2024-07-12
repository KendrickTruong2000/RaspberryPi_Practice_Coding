/* 
#if                 //Evaluates the expression/ condition
#ifdef (identifier) //Check if an identifer has been define
#ifndef identifier  //Check if an identifier has not been defined 
#undef identifier   //Remove the deinition of an identifier 
#else #elseif       //Indicaate alternative statements of an if directive 
#endif              //Used to indicate the end of an if directive 
#error message      //Display an error message, and stop building 
#warning message    //Display a warning message
*/

#include <stdio.h>

#ifndef X
#define X 12
#endif

#define AREA(a,b) (a * b)

int main(){
    int l1 = 19, l2 = 5, area;
    area = X*AREA(l1,l2);
    printf("Total area is: %d", area)
    return 0;
}