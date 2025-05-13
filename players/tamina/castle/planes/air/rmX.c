inherit "/room/room";

#include "/players/tamina/defs.h"

reset(arg) 
{
  if (!arg) 
  {

    timer  = 4;
    damage = 25;
    survivor = "necklace";
    envname  = "air";
    saymsg   = "seems to be unable to breathe.";
    wrtmsg   = "There is not enough oxygen to breathe!";
    property = ({"in_air", "no_teleport" });

    set_light(1);
    short_desc = "";
    long_desc = 
"   Where you are, you can see nothing but a white mass of solid\n"+
"   cloud on which you are standing.  You can see for miles into\n"+
"   the distance, in all directions, but with virtually nothing\n"+
"   on the horizon.  Where will you go ?\n";
    no_obvious_msg = "";

    items = ({
  "clouds",
"Large white puffy clouds, that seem to be solid enough to walk on",
  "cloud",
"A large white puffy cloud, that seems to be solid enough to walk on",
    });

  }

}

init() {
  ::init();
  AA("go_n",  "north");
  AA("go_s",  "south");
  AA("go_e",  "east");
  AA("go_w",  "west");
  AA("go_ne", "northeast");
  AA("go_nw", "northwest");
  AA("go_se", "southeast");
  AA("go_sw", "southwest");
}

int go_n ()
{
  write("You leave north.\n");
  MPL("north.#/players/tamina/castle/planes/air/no_room");

  return 1;
}

int go_s ()
{
  write("You leave north.\n");
  MPL("north.#/players/tamina/castle/planes/air/no_room");

  return 1;
}

int go_e ()
{
  write("You leave north.\n");
  MPL("north.#/players/tamina/castle/planes/air/no_room");

}

int go_w ()
{
  write("You leave north.\n");
  MPL("north.#/players/tamina/castle/planes/air/no_room");

  return 1;
}

int go_ne ()
{
  write("You leave north.\n");

}

int go_nw ()
{
  write("You leave north.\n");
  MPL("north.#/players/tamina/castle/planes/air/no_room");

  return 1;
}

int go_se ()
{
  write("You leave north.\n");
  MPL("north.#/players/tamina/castle/planes/air/no_room");

  return 1;
}

int go_sw ()
{
  write("You leave north.\n");
  MPL("north.#/players/tamina/castle/planes/air/no_room");

  return 1;
}
