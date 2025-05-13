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
"   You are standing in a conjoining passageway between the previous\n"+
"   junction, and the structure ahead of you.  There don't seem to\n"+
"   be many pathways, and you could easily be swept away in the clouds...\n";

    no_obvious_msg = "         There are exits in all directions...\n";
    exit_num = random(8);

    items = ({
  "clouds",
"Large white puffy clouds, that seem to be solid enough to walk on",
  "cloud",
"A large white puffy cloud, that seems to be solid enough to walk on",
  "structure",
"It seems to constructed out of solid cloud formations.  Whether or not "+
"it is safe for you to go towards, you can only find out by trying..",
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
    MPL("south#/players/tamina/castle/planes/air/rm7");
    write("   You feel you have advanced somewhat.\n");
    return 1;
  }
  else
    MPL("south#/players/tamina/castle/planes/air/rm5");
  return 1;
}

int go_s()
{
  if (exit_num == 1)
  {
    MPL("south#/players/tamina/castle/planes/air/rm7");
    write("   You feel you have advanced somewhat.\n");
    return 1;
  }
  else
    MPL("south#/players/tamina/castle/planes/air/rm4");
  return 1;
}

int go_e()
{
    MPL("east#/players/tamina/castle/planes/air/rm5");
  return 1;
}

int go_w()
{
  MPL("west#/players/tamina/castle/planes/air/rm7");
  write("   You feel you have advanced somewhat...\n"); 
  return 1;
}

int go_ne()
{
  if (exit_num == 4)
  {
    MPL("south#/players/tamina/castle/planes/air/rm7");
    write("   You feel you have advanced somewhat.\n");
    return 1;
  }
  else
    MPL("south#/players/tamina/castle/planes/air/rm5");
  return 1;
}

int go_nw()
{
  if (exit_num == 5)
  {
    MPL("south#/players/tamina/castle/planes/air/rm7");
    write("   You feel you have advanced somewhat.\n");
    return 1;
  }
  else
    MPL("south#/players/tamina/castle/planes/air/rm5");
  return 1;
}

int go_se()
{
  if (exit_num == 6)
  {
    MPL("south#/players/tamina/castle/planes/air/rm7");
    write("   You feel you have advanced somewhat.\n");
    return 1;
  }
  else
    MPL("south#/players/tamina/castle/planes/air/rm6");
  return 1;
}

int go_sw()
{
  if (exit_num == 7)
  {
    MPL("south#/players/tamina/castle/planes/air/rm7");
    write("   You feel you have advanced somewhat.\n");
    return 1;
  }
  else
    MPL("south#/players/tamina/castle/planes/air/rm6");
  return 1;
}
