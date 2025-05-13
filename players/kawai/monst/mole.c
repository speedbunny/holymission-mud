inherit "obj/monster";
#include <lw.h>

int count;
mixed walk;

void reset(int arg)
  {::reset();
  if(!arg)
    {count=0;
    set_name("A mole");
    set_alias("mole");
    set_race("mole");
    set_short("A small mole");
    set_long(lw("While harmless looking at first, the little mole is the scourge of all "+
    "farmers, devouring roots and eating crops.  This one looks particularly "+
    "nasty....with big pointy teeth...and (Ok...enough of the Monty Python "+
    "parallels...)\n"));
    set_level(5);
    set_wc(5);  
    set_al(0);
    set_whimpy(50);
    add_money(15+random(50));
    walk=({ "north", "east", "south", "west"});}}

void heart_beat()
  {::heart_beat();
  if(environment(this_object()) && ++count>4)
    {command(walk[random(4)],this_object());
    count=0;}}



