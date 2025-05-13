inherit "/room/room";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  ::reset(arg);
  if (arg) return 0;

    property = ({ "has_earth", "no_teleport" });
    smell = "The huge amounts of Earth gets clogged up your nose!\n";

	set_light(0);
	short_desc = "";
	long_desc = 
"    The bending passage strangely comes to an end here.\n"+
"    The walls end in what appears to be as smooth a dead-end\n"+
"    as you have seen before.\n";

     	dest_dir = ({
      EARTH + "rm14", "northwest",
	});

	items = ({
  "walls",
"You see the smoothest walls curving round in perfect circular "+
"regularity.  But, there is a tiny crack in the surface of the floor "+
"on which you stand..",
  "crack",
"It looks ever so tiny, and now that you take a closer look, you see that "+
"the reflective nature of the walls around you make the crack look "+
"deceptively smaller than it actually is.  If you are small enough, perhaps "+
"you might be able to enter it ..",
      });

}

void init()
{
  ::init();
  AA("_enter", "enter");
}

int _enter(string arg)
{
  if (arg == "crack" || arg == "the crack")
  {
    if (TP->query_size() > 2)
    {
      write("But you are too large to fit in here !!\n");
      say(TPN+" tries in vain to squeeze into the small crack in the floor.\n");

      return 1;
    }
    write("You find that the crack is small enough for you to squeeze through.\n");
    MPL("through a crack in the floor", EARTH + "rm16");

    return 1;
  }
}
