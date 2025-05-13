#include <stdio.h>
#include <sys/time.h>    /* Used for the time element for the random Seed */
#define NOCOMMON  75     /* Defines the number of cards to read in from */
#define NOUNCOMMON  75   /* the varies files to make the random selection */
#define NORARE  80       /* with. */
#define NOARTIFACT 47
void initialise();
void common_get();
void uncommon_get();
void rare_get();
void artifact_get();
void land_get();
void rare_land_get();
char *color_check(int check);
char *type_check(int check);

char buffer[80];

typedef struct card {   /* The basic Card structure */
  int card_color;       
  int card_type;
  char card_name[80];
}card;

card rare[NORARE];
card common[NOCOMMON];
card uncommon[NOUNCOMMON];
card artifact[NOARTIFACT];
FILE *fp_o;
time_t seed;          /* Used as the seed for the random function */

int main()
{
  int noofspells, noofland;
  int percentage;

/* Initialise seed with the current time so that it is different every time
    the program is run to produce random. */
  time(&seed);
/* Srand - This is the random number initialiser. */
  srand(seed);

  initialise();
  do
    {
    printf("How many cards do you want as spells??? (25-55) :");
    scanf("%d",&noofspells);
  } while (!(noofspells >= 25) && (noofspells <= 55));
  noofland=65-noofspells;
  while(noofspells--) {

/* Percentage is a random number from 1 - 100. The rand function is called
   and this produces a pseudo random number from 0 - MAXINT. This is the
   put through a modulus operator to get a number from 0 - (N-1). (Where N 
   is the number of the modulus). One is then added to get the number from
   one to one hundred. 
*/
    percentage=(rand()%100)+1;
    if (percentage >= 29)
      common_get();
    else if (percentage >= 3)
      uncommon_get();
    else
      rare_get();
  }
  while(noofland--) {
    if (percentage=(rand()%100)+1 > 2)
      land_get();
    else
      rare_land_get();
  }
  percentage = (rand()%2)+1;
    while(percentage--)
      artifact_get();
  fclose(fp_o);
}

void initialise(void)
{
  FILE *fp_r, *fp_u, *fp_c, *fp_a;
  int lines;
  char junk[100];
  
  fp_r=fopen("spell-rare","r");
  fp_u=fopen("spell-uncommon","r");
  fp_c=fopen("spell-common","r");
  fp_a=fopen("spell-artifact","r");
  fp_o=fopen("pack","w");

  for(lines=0;lines<NORARE;lines++) {
    fscanf(fp_r,"%d%d", &rare[lines].card_color, &rare[lines].card_type);
    fgets( rare[lines].card_name , 80,  fp_r);
  }
  for(lines=0;lines<NOUNCOMMON;lines++) {
    fscanf(fp_u,"%d%d", &uncommon[lines].card_color, 
	   &uncommon[lines].card_type);
    fgets( uncommon[lines].card_name, 80, fp_u);
  }
  for(lines=0;lines<NOCOMMON;lines++) {
    fscanf(fp_c,"%d%d", &common[lines].card_color, 
	   &common[lines].card_type);
    fgets( common[lines].card_name, 80, fp_c);
  }
  for(lines=0;lines<NOARTIFACT;lines++) {
    fscanf(fp_a,"%d%d", &artifact[lines].card_color, 
	   &artifact[lines].card_type);
    fgets( artifact[lines].card_name, 80, fp_a);
  }
  fclose(fp_r);
  fclose(fp_u);
  fclose(fp_c);
}  

void common_get()
{
  int percentage;
  
  percentage=(rand()%NOCOMMON)+1;
  fprintf(fp_o,"C   %15s\t%20s\t%s", 
	  color_check(common[percentage].card_color),
	  type_check(common[percentage].card_type),
	  common[percentage].card_name);

}

void uncommon_get()
{
  int percentage;
  
  percentage=(rand()%NOUNCOMMON)+1;
  fprintf(fp_o,"U   %15s\t%20s\t%s", 
	  color_check(uncommon[percentage].card_color),
	  type_check(uncommon[percentage].card_type),
	  uncommon[percentage].card_name);

}

void rare_get()
{
  int percentage;
  
  percentage=(rand()%NORARE)+1;
  fprintf(fp_o,"R   %15s\t%20s\t%s", 
	  color_check(rare[percentage].card_color),
	  type_check(rare[percentage].card_type),
	  rare[percentage].card_name);

}

void artifact_get()
{
  int percentage;
  
  percentage=(rand()%NOARTIFACT)+1;
  fprintf(fp_o,"A   %15s\t%20s\t%s", 
	  "Brown",
	  type_check(artifact[percentage].card_type),
	  artifact[percentage].card_name);

}
  
void land_get()
{
  int land;
  char *land_name;

  land=rand()%5+1;
  switch(land){
  case 1:
    land_name = "Island\n";
    break;
  case 2:
    land_name = "Mountain\n";
    break;
  case 3:
    land_name = "Forest\n";
    break;
  case 4:
    land_name = "Swamp\n";
    break;
  case 5:
    land_name = "Plains\n";
    break;
  }
  fprintf(fp_o,"L   %15s\t%20s\t%s", color_check(land), "Land",
	  land_name);
}

void rare_land_get()
{
  char *land_color;
  char *land_name;
  int land;

  land=(rand()%10)+1;
  switch(land){
  case 1:
    land_name = "Badlands\n";
    land_color = "Black/Red";
    break;
  case 2:
    land_name = "Bayou\n";
    land_color = "Black/Green";
    break;
  case 3:
    land_name = "Plateau\n";
    land_color = "Red/White";
    break;
  case 4:
    land_name = "Savanah\n";
    land_color = "Green/White";
    break;
  case 5:
    land_name = "Scrubland\n";
    land_color = "Black/White";
    break;
  case 6:
    land_name = "Taiga\n";
    land_color = "Green/Red";
    break;
  case 7:
    land_name = "Tropical Island\n";
    land_color = "Blue/Green";
    break;
  case 8:
    land_name = "Tundra\n";
    land_color = "Blue/White";
    break;
  case 9:
    land_name = "Underground Sea\n";
    land_color = "Black/Blue";
    break;
  case 10:
    land_name = "Volcanic Island\n";
    land_color = "Blue/Red";
    break;
  }
 fprintf(fp_o,"RL  %15s\t%20s\t%s", land_color, "Land", land_name);
}

char *color_check(int check)
{
  switch(check) {
  case 1:
    return "Blue";
    break;
  case 2:
    return "Red";
    break;
  case 3:
    return "Green";
    break;
  case 4:
    return "Black";
    break;
  case 5:
    return "White";
    break;
  case 6:
    return "Brown";
    break;
  }
}

char *type_check(int check)
{
  switch(check) {
  case 1:
    return "Enchantment";
    break;
  case 2:
    return "Instant";
    break;
  case 3:
    return "Sorcery";
    break;
  case 4:
    return "Enchant Artifact";
    break;
  case 5:
    return "Enchant Creature";
    break;
  case 6:
    return "Enchant Enchantment";
    break;
  case 7:
    return "Enchant Land";
    break;
  case 8:
    return "Summon";
    break;
  case 9:
    return "Interrupt";
    break;
  case 10:
    return "Enchant Wall";
    break;
  case 11:
    return "Artifact-Continuous";
    break;
  case 12:
    return "Artifact-Mono";
    break;
  case 13:
    return "Artifact-Poly";
    break;
  case 14:
    return "Artifact-Creature";
    break;
  }
}

