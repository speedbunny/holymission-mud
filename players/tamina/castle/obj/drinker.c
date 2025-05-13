/*  This is the ring, Drinker  */

#include "/players/tamina/defs.h"

inherit "obj/armour";

reset(arg) 
{
  ::reset(arg);
  if (arg != 0) return;

    set_name("drinker");
    set_alias("ring");
    set_type("ring");
    set_short("Drinker, the Ring");
    set_long(
  "This is a marvellous, blood-red ring.\n"+
  "You can see a series of etched runes on the golden band.\n"+
  "The ring glows with a strange fire.\n");
    set_size(0);
    set_ac(1);
    set_weight(1);
    set_value(5000); 
}

int query_mage_wear()     { return 1; }
int query_monk_wear()     { return 1; }
int query_ninja_wear()    { return 1; }
int query_summoner_wear() { return 1; }

void init() 
{
  ::init();
  add_action("_read","read");
}

int wear_fun(object ob) 
{
  object shad;

  if (!ob->drinker_shad())
  {
    shad = clone_object(COBJ + "drinker_shad");
    shad->start_shadow(ob, 0, "drinker_shad");
    write("You feel your blood surge through your veins again.\n");
  }
  return 1;
}

int remove_fun(object ob) 
{
  if (ob->drinker_shad())
  {
    destruct(ob->drinker_object());
    write("Your blood's pace returns to normal, when you remove Drinker.\n");
  }
  return 1;
}

drop (sil) 
{
  remove("ring");
}

string query_info() 
{
  return("This is the Ring, Drinker.\n"+
         "If worn, and you spill blood, you are healed faster.\n");
}

int _read(string str) 
{
  if (!id(str) && str != "runes") 
  {
    NFAIL("Read what?\n");
    return 0;
  }
  write("The etched runes seem to say:\n"+
        "When Drinker is worn, Death will seem far away.\n"+
        "But, when Drinker has Drunk, Death will speed on his way!\n");
  return 1;
}

