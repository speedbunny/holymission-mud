inherit "room/room";

#include "/players/tamina/defs.h"

object gob;

void reset(int arg) 
{
  ::reset (arg);
  if (arg) return 0;

     set_light(1);
     short_desc = "Petrified Forest";
     long_desc =
   "You stand in a smaller clearing in the Petrified Forest.\n"+
   "This clearing extends further to the south.\n";

     dest_dir = ({
   TFOREST + "rmZ","north",
   TFOREST + "rmO","south",
   TFOREST + "rmT","west",
     });

  if (!gob = present("goblin") && !living(gob))
  { 
    MO (CLO (TMONS + "goblin"), TO);
    MO (CLO (TMONS + "goblin"), TO);
    MO (CLO (TMONS + "goblin"), TO);
    MO (CLO (TMONS + "goblin"), TO);
  }
}

move(str) 
{
  object goblin;

  if (!str) 
    str = query_verb();
  if (str == "north" || str == "west") 
    return ::move(str);

  goblin = present("goblin");
  if (goblin) 
  {
     write("The Forest Goblins bar your path!!\n");
     goblin->attack_object(TP);
     return 1;
  }
  if (str = "south") 
    return ::move(str);
}
