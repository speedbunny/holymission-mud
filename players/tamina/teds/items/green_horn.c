inherit "obj/treasure";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  if (arg) return;

  set_name("green horn");
  set_alias("horn");
  set_short("An Olive Green Horn");
  set_long(
"A beautifully carved horn, made from a green dragons skull.\n\n"+
"A small plaque reads:\n\nBlow horn to challenge Knight\n");
  set_weight(25);
}

int get() 
{
  write("The horn is securly fastened to the tree!\n");
  return 0;
}

void init() 
{
  ::init();
  add_action("_blow", "blow"); 
}

int _blow(string str) 
{
  object knight;

  if (str == "horn" && !present("green knight")) 
  {
    write("\nThe Green Knight jumps out of his pavilion !!\n");
    say(TPN+" blows the horn.\n"+
        "The Green Knight comes out of his pavilion\n");

    knight = CLO(TMONS + "green_knight");
    call_other("/players/tamina/teds/random_magic","make_item", knight, 19);

    MO(knight, E(TP));
    knight->attack_object(TP);

    destruct(TO);
    return 1;
  }
  else
  {
    NFAIL("Blow what?\n");
    return 0;
  }
}
