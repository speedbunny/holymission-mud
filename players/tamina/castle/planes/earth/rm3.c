inherit "/room/room";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  ::reset(arg);
  if (!arg)
    {
      property = ({ "has_earth", "no_teleport" });
      smell = "The huge amounts of Earth gets clogged up your nose!\n";

	set_light(0);
	short_desc = "";
	long_desc = 
"    The featureless tunnels continue on north here, until you reach\n"+
"    what appears to be a pile of loose Earth, which you presume has\n"+
"    fallen from the roof.  You can however nimbly walk around this\n"+
"    and continue along the trail.\n";

     	dest_dir = ({
      EARTH + "rm2", "south",
      EARTH + "rm4", "west",
	});

	items = ({
  "roof",
"You are not sure, but is it _really_ safe?",
  "earth",
"Just some very fine particles of dirt..",
  "Earth",
"Just some very fine particles of dirt..",
      });

    }
}

init() {
  ::init();
  AA("_search",  "search");
}

int _search(string str)
{
  if (str == "Earth" || str == "earth")
  {
    write("You search through the pile of Earth, but find nothing of interest.\n"); 
      say(TPN+" searches through the pile of Earth.\n");
    return 1;
  }
  else
  {
    NFAIL("Search what?\n");
    return 0;
  }
}
