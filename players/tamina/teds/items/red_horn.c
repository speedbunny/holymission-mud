inherit "obj/treasure";

#include "/players/tamina/defs.h"

object knight;

void reset(int arg) 
{
  if(arg) return 0;

  set_name("Red Horn");
  set_id("red horn");
  set_alias("horn");
  set_short("A Blood Red Horn");
  set_long(
"This massive horn was carved from the skull of a red dragon.\n\n"+
"A small plaque reads:\n\n         Blow horn to challenge Knight\n");
}

int get() 
{
  write("The horn is securly fastened to the oak tree\n");
  return 0;
}

void init() 
{
  ::init();
  add_action("_blow", "blow"); 
}

int _blow(string str) 
{
  if (str == "horn" && !present("red knight")) 
  {
    write("The Red Knight bounds out of his pavilion !!\n");
    say(TPN+" blows the Red Horn.\n"+
        "The Red Knight comes out of his pavilion.\n");

    knight = CLO("players/tamina/teds/r_knight");
    call_other("players/tamina/teds/random_armor", "make_item", knight, 16);
    call_other("players/tamina/teds/random_magic", "make_item", knight, 16); 

    MO(knight, E(TP));

    knight->attack_object(TP);
    knight->command("powerup");
    destruct(TO);
    return 1;
  }
  else
  {
    NFAIL("Blow what?\n");
    return 0;
  }
}
