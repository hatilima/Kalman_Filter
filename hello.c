#include<stdio.h>

enum week {sunday = 4, monday, tuesday, wednesday, friday, saturday };
int main()
{
  /*testing enumeration: creating user defined data type for integral constants or a variable */
  
  enum week today;
  today = wednesday;
  printf("Day %d",today+1);
  return 0;
}
