/*  This is a small hut in the Dread Forest  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
  if (arg) return ;

      	set_light(0);
	short_desc = "Outside a small hut (w,enter)";
	long_desc = 
"You stand outside what appears to be a small hut\n"+
"standing in what must be the smallest clearing you\n"+
"have seen in this Forest.\n";

	dest_dir = ({
          FOREST + "rm41","west",
        });

	items = ({
  "hut",
"A small wooden hut, with a narrow, open doorway.  You cannot see much "+
"inside as it is so shadowed and dark here.  But you do not sense so "+
"much evil coming from this place",
  "clearing",
"You are standing in what can hardly be called a clearing.\n"+
"It is very small, only wide enough to contain this small hut, and no more",
     });

}

init() 
{
  ::init();
  AA("_enter", "enter");
}

int _enter(string str)
{
  if (str == "hut" || str == "house")
  {
    write("You creep quietly into the small hut.\n");
    MPL("into the hut.#/players/tamina/castle/rooms/forest/hut");

    return 1;
  }
  NFAIL("Enter what?\n");
  return 0;
}

