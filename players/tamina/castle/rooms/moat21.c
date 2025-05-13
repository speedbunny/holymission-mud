/* Camelot's Moat */

#include "/players/tamina/defs.h"

inherit "room/room";
object serpent;

void reset(int arg) 
{
  if (!serpent)
    MO (serpent = CLO(CMONS + "serpent"), TO);
  ::reset(arg);
  if (arg) return 0;

     set_light(1);
     short_desc = "Camelot's Moat";
     long_desc =
"You continue onwards so that the water is now up to the top of your \n"+
"chest.  It is very cold, and making your skin come out in goose-bumps.\n"+ 
"The bank beside you now is so high that you have no hope of climbing \n"+
"out of it...\n";

      dest_dir = ({
        CROOMS + "moat2", "west",
        "", "east",
    });

      items = ({
  "bank",
"It stretches up a full 12 feet to the ground",
    });

}

void init() 
{
  ::init();
  AA("swim",     "swim");
  AA("swim",     "dive");
  AA("drink",    "drink");
  AA("no_way",   "east");
  AA("no_climb", "climb");
}

int swim(string str)
{
  if (!str || str == "water" || str == "in water")
  { 
     write("You go for a dive in the rather dirty water.\n");
       say(TPN+" dives underneath the surface of the water.\n");

     MPL("beneath the surface of the water#/players/tamina/castle/rooms/umoat");

     return 1;
  }
}

int drink(string str)
{
  if (!str || str == "water")
  {
    write("Glug    Glug    Glug !!\n"+
	  "You take a drink from the dirty water.\n"+
	  "     -=  Yeuch !! =-\n");
      say("You hear a 'glugging' sound coming from "+TPN+".\n");

    return 1;
  }
}

int no_way()
{
  write("You see that the ripples are too strong for you to dare going\n"+
        "in that direction...\n");
  return 1;
}

int no_climb(string str)
{
  if (str == "bank" || str == "wall")
  {
    write("You do not manage to make it up the bank...\n"+
          "And fall back down to the water, with a resounding\n\n"+
          "          * * * S P L A S H * * *\n\n");
    return 1;
  }
  else
  {
    NFAIL("Climb where?\n");
    return 0;
  }
}

