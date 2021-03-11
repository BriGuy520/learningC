#include <stdio.h>


int main()
{

  char lead;
  char *sidekick;
  lead = 'A';
  sidekick = &lead;
  printf("About variable 'lead' \n");
  printf("Size\t%ld", sizeof(lead));
  printf("\nContents %c\n", lead);
  printf("Location%p\n", &lead);
  printf("And vaiable sidekick\n");
  printf("Content %p\n", sidekick);

  return 0;
}