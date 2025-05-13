/* PIT.C, Programmed by Ted */
/* 270593: Ethereal Cashimor: heart_beat bug fixed */
/* 230793: Galadriel: some typos fixed and new hurt message */

inherit "room/room";

#include "/players/tamina/defs.h"

int climbing;

void reset(int arg) 
{
  ::reset(arg);
  if (!arg) 
  {
    set_light(0);
    short_desc = "Bottom of Pit";
    long_desc = 
  "You are at the bottom of a pit. The walls are made from the "+
  "rough cut rock of the mountain.\n";

    items = ({
  "walls",
"It looks like you might be able to climb up the\n"+ 
"side of the pit if you are light and strong",              
  "wall",
"It looks like you might be able to climb up the\n"+ 
"side of the pit if you are light and strong"
    });

    smell="The smell of death lingers here.";
  }
}

void init() 
{
  ::init();
  add_action("_climb", "climb");
}

int _climb(string str) 
{
  if (str == "wall" || str == "walls")
  {
    if (climbing) 
    {
      write("Someone else is blocking the way.\n");
      return 1;
    }
    if (TP->query_guild() == 1)   // The thieves can do it  :)
    {
      write("You easily climb up the side of the pit.\n");
      say(TPN+" climbs up the side of the pit.\n");
      MPL("up#players/tamina/teds/frost/cave13");
      return 1;
    }
    if (TP->query_ghost()) 
    {
      write("You drift up the side of the pit.\n");
      MPL("up#players/tamina/teds/frost/cave13");
      return 1;
    }
    if (TP->query_weight() > (3 + TP->LVL/4)) 
    {
      write("You are carrying too much stuff!\n");
      say(TPN+" tries to climb the wall, but slips back down.\n");
      return 1;
    }
    write("You begin to climb up the wall of the pit.\n");
    say(TPN+" begins to climb the wall of the pit.\n");
    climbing = 1;
    call_out("climb_it", 3);
    return 1;
  }
  else
  {
    notify_fail("Climb what?\n");
    return 0;
  }
}

int climb_it() 
{
  climbing = 0;
  if (random(100)>42) 
  {
    TRM(TO, TPN+" slips and falls back to the floor!\n");
    TOBJ(TP, "You slip and fall back to the floor, that hurts!\n");
    HIT(6);
    return 1;
  }
  TOBJ(TP, "You climb out of the pit.\n");
  MPL("out of the pit#players/tamina/teds/frost/cave13");
}
