#include<stdio.h>

enum week {sunday = 4, monday, tuesday, wednesday, friday, saturday };
int main()
{
  enum week today;
  today = wednesday;
  printf("Day %d",today+1);
  return 0;
}
