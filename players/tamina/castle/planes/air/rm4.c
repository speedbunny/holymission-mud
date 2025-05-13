inherit "/room/room";

#include "/players/tamina/defs.h"

int exit_num;

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
    short_desc = "On the Plane of Air";
    long_desc = 
"   Where you are, you can see nothing but a white mass of solid\n"+
"   cloud on which you are standing.  You can see for miles into\n"+
"   the distance, in all directions, but with virtually nothing\n"+
"   on the horizon.  Where will you go ?\n";

    no_obvious_msg = "         There are exits in all directions...\n";
    exit_num = random(8);

    items = ({
  "clouds",
"Large white puffy clouds, that seem to be solid enough to walk on",
  "cloud",
"A large white puffy cloud, that seems to be solid enough to walk on",
    });

  }

}

void init() 
{
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

int go_n()
{
  if (exit_num == 0)
  {
    write("   You feel you have advanced somewhat...\n");
    MPL("north#/players/tamina/castle/planes/air/rm5");
    return 1;
  }
  else
    MPL("north#/players/tamina/castle/planes/air/rm3");
  return 1;
}

int go_s()
{
  if (exit_num == 1)
  {
    write("   You feel you have advanced somewhat...\n");
    MPL("south#/players/tamina/castle/planes/air/rm5");
    return 1;
  }
  else
    MPL("south#/players/tamina/castle/planes/air/rm2");
  return 1;
}

int go_e()
{
  if (exit_num == 2)
  {
    write("   You feel you have advanced somewhat...\n");
    MPL("east#/players/tamina/castle/planes/air/rm5");
    return 1;
  }
  else
    MPL("east#/players/tamina/castle/planes/air/rm1");
  return 1;
}

int go_w()
{
  if (exit_num == 3)
  {
    write("   You feel you have advanced somewhat...\n");
    MPL("west#/players/tamina/castle/planes/air/rm5");
    return 1;
  }
  else
    MPL("west#/players/tamina/castle/planes/air/rm2");
  return 1;
}

int go_ne()
{
  if (exit_num == 4)
  {
    write("   You feel you have advanced somewhat...\n");
    MPL("northeast#/players/tamina/castle/planes/air/rm5");
    return 1;
  }
  else
    MPL("northeast#/players/tamina/castle/planes/air/rm3");
  return 1;
}

int go_nw()
{
  if (exit_num == 5)
  {
    write("   You feel you have advanced somewhat...\n");
    MPL("northwest#/players/tamina/castle/planes/air/rm5");
    return 1;
  }
  else
    MPL("northwest#/players/tamina/castle/planes/air/rm4");
  return 1;
}

int go_se()
{
  if (exit_num == 6)
  {
    write("   You feel you have advanced somewhat...\n");
    MPL("southeast#/players/tamina/castle/planes/air/rm5");
    return 1;
  }
  else
    MPL("southeast#/players/tamina/castle/planes/air/rm3");
  return 1;
}

int go_sw()
{
  if (exit_num == 7)
  {
    write("   You feel you have advanced somewhat...\n");
    MPL("southwest#/players/tamina/castle/planes/air/rm5");
    return 1;
  }
  else
    MPL("southwest#/players/tamina/castle/planes/air/rm2");
  return 1;
}
