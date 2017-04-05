#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PREFIX  "/sys/class/power_supply"
#define BAT     "/BAT1"

int main(int argc,char** argv)
{
  char buf[BUFSIZ];
  unsigned long voltage_now;
  unsigned long voltage_min_design;
  unsigned long energy_now;
  unsigned long energy_full_design;
  unsigned long energy_full;
  unsigned long current_now;
  FILE *in = NULL;

  snprintf(buf,BUFSIZ,"%s/%s/current_now",PREFIX,BAT);
  in = fopen(buf,"r");
  if (!in)
    {
    	printf("error\n");
	  return -1;
    }
  fgets(buf,BUFSIZ,in);
  fclose(in);
  sscanf(buf,"%lu",&current_now);

  snprintf(buf,BUFSIZ,"%s/%s/voltage_now",PREFIX,BAT);
  in = fopen(buf,"r");
  if (!in)
    {
    	printf("error\n");
      return -1;
    }
  fgets(buf,BUFSIZ,in);
  fclose(in);
  sscanf(buf,"%lu",&voltage_now);

  snprintf(buf,BUFSIZ,"%s/%s/energy_now",PREFIX,BAT);
  in = fopen(buf,"r");
  if (!in)
    {
    	printf("error\n");
      return -1;
    }
  fgets(buf,BUFSIZ,in);
  fclose(in);
  sscanf(buf,"%lu",&energy_now);

  snprintf(buf,BUFSIZ,"%s/%s/energy_full",PREFIX,BAT);
  in = fopen(buf,"r");
  if (!in)
    {
    	printf("error\n");
      return -1;
    }
  fgets(buf,BUFSIZ,in);
  fclose(in);
  sscanf(buf,"%lu",&energy_full);

  snprintf(buf,BUFSIZ,"%s/%s/status",PREFIX,BAT);
  in = fopen(buf,"r");
  if (!in)
    {
    	printf("error\n");
      return -1;
    }
  fgets(buf,BUFSIZ,in);
  fclose(in);
  char *p = NULL;
  for (p=buf ; *p != '\0' ; p++)
    if(*p == '\n')
      *p = '\0';
  printf("Status: %s\n",buf);
  printf("Current:  %g W\n",current_now/1000000.0);
  printf("Voltage:  %g V\n",voltage_now/1000000.0);
  printf("Energy:   %g Wh\n",energy_now/1000000.0);
  printf("Capacity: %g Wh\n",energy_full/1000000.0);

  FILE *out = fopen("/tmp/battery-status.log","a+");
  if (!out)
    {
    	printf("error\n");
      return -2;
    }
  time_t now = time(NULL);
  fprintf(out,"%lu %s %lu %lu %lu %lu\n",now,buf,current_now,voltage_now,energy_now,energy_full);

  return 0;
}
