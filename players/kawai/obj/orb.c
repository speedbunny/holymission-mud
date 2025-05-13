inherit "obj/treasure";
#include <lw.h>

int isdead;

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {set_id("kq1-orb");
    set_alias("orb");
    set_alt_name("glowing orb");
    set_weight(1);
    set_light(5);
    set_short("A bright glowing orb");
    set_long(lw("It is impossible to determine the nature of the orb, as it is perhaps "+
    "the strangest artifact you've yet seen.  The orb radiates an incredible "+
    "amount of light, yet, for reasons unknown, is still very cold.\n"));
    set_value(2000);}}


int drop()
  {if(isdead)
    {return 0;}
  isdead=1;
  write("As you release the orb it suddenly stops glowing!\n");
  set_id("rock");
  set_alias("rock");
  set_name("A spherical rock");
  set_short("A perfectly spherical rock");
  set_long(lw("Although nice and round, it is nothing more than a rock.  Perhaps "+
  "you could go bowling or something?\n"));
  set_value(50);
  return 0;}

int query_quest_obj()
  {return 1;}
