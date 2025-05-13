inherit "/room/room";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  ::reset(arg);
  if (arg) return 0;

      property = ({ "has_earth", "no_teleport" });
      smell = "The huge amounts of Earth gets clogged up your nose!\n";

	set_light(0);
	short_desc = "On the Second Level";
	long_desc = 
"    Above you is a hole in the roof of this cave, leading to an upper\n"+
"    level in what is know seeming to be a labyrinth of sorts.  The walls\n"+
"    around you seem to have become more solid and tangible on this level,\n"+
"    so that the Earth is only in small quantities here.\n"+
"    This tunnel leads, in a more straighter line, in three directions, \n"+
"    each of which being as dark and foreboding as the other...\n";

     	dest_dir = ({
      EARTH + "rm8", "north",
      EARTH + "rm9", "south",
      EARTH + "rm11", "west",
	});

	items = ({
  "walls",
"They know look as though they have been carved, rather than the natural "+
"formation of the walls of the tunnels in the upper levels.  But they still "+
"do not look like any manner of crafting or caving that you have seen before",
  "tunnel",
"It seems to be a junction of some kind, with the three different passages "+
"leading off, and the hole in the roof leading back into the upper level",
  "earth",
"It looks very fine and of a strange quality, compared to that sort of "+
"Earth that you are so used to",
      });

}

void init()
{
  ::init();
  AA("_climb",  "climb");
}

int _climb(string str)
{
  if (str == "up" || str == "hole")
  {
    if (TP->DEX < 25)
    {
      write("You start to climb up the small tunnel in the ceiling...\n");
        say(TPN+" climbs up the tunnel in the ceiling.\n"); 
      call_out("mover", 8);
      return 1;
    }
    write("You start to climb up the small tunnel in the ceiling...\n");
      say(TPN+" climbs up the tunnel in the ceiling.\n"); 
    call_out("mover", 5);
    return 1;
  }
  else
  {
    NFAIL("Climb where?\n");
    return 0;
  }
}

int mover()
{
  TOBJ (TP,
   "You slowly manage to climb to the top of the long narrow tunnel,\n"+
   "and find yourself again on the first level.\n");
  MPL ("up to the first level.#/players/tamina/castle/planes/earth/rm6");

  return 1;
}
 

