inherit "obj/armour";

#include "/players/tamina/defs.h"

status worn;

void reset(int arg) 
{
  ::reset(arg);
  if(arg != 0) return;

  set_name("ring of light");
  set_type("ring");
  set_size(0);
  set_short("Ring of Light");
  set_ac(1);
  set_weight(1);
  set_value(1500);
}

long()
{
  if (worn)
    write("The Ring of Light blazens with a powerful glow.\n"+
	  "It feels very warm on your finger.\n");
  else
    write("The plain gold band seems to hum with an inner power.\n");
}

int wear_fun(object ob)
{
  write("The Ring of Light flares with magical power, creating\n"+
        "an aura of light around you.\n");
  worn = 1;
  set_arm_light(3);
  return 1;
}

int remove_fun(object ob)
{
  write("The aura of light around you fades when you remove the \n"+
	"Ring of Light.\n");
  worn = 0;
  set_arm_light(-3);
  return 1;
}

int query_mage_wear() { return 1; }
int query_monk_wear() { return 1; }
int query_ninja_wear() { return 1; }
int query_summoner_wear() { return 1; }

