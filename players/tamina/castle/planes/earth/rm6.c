inherit "/room/room";

#include "/players/tamina/defs.h"
  status shifted, searched;

void reset(int arg)
{
  ::reset(arg);
  if (arg) return;

      property = ({ "has_earth", "no_teleport" });
      smell = "The huge amounts of Earth gets clogged up your nose!\n";

	set_light(0);
	short_desc = "";
	long_desc = 
"    You have come to end of the tunnel.\n"+
"    In front of you is a complete wall of the gradual mix of Earth\n"+
"    and stone.  Littered across the floor are various rocks that must\n"+
"    have fallen from the roof of the tunnel.  @@check_floor@@";

     	dest_dir = ({
      EARTH + "rm5", "northeast",
	});

	items = ({
  "wall",
"There is definitely more stone in the constitution of the walls now...\n"+
"The explanation of this is of yet unknown to you",
  "walls",
"There is definitely more stone in the constitution of the walls now...\n"+
"The explanation of this is of yet unknown to you",
  "floor",
"There are all manner of rocks strewn across the floor",
  "rocks",
"Some are very large, and some are quite small",
  "large rocks",
"These are rather heavy looking boulders.  Perhaps you are strong enough "+
"to shift them...",
  "small rocks",
"These are small, pebbles strewn across the floor",
  "hole",
"@@check_hole@@",
      });

}

init()
{
  AA("_search", "search");
  AA("_shift",  "shift");
  AA("_enter",  "enter");
  call_out("faller", 10);
  ::init();
}

int _search(string str)
{
  if (str == "rocks") 
  {
    write("You search through the rocks, and manage to find a larger\n"+
	  "one, that looks as thought it is hiding something beneath it...\n");
      say(TPN+" searches through the piles of rocks on the floor.\n");

    searched = 1;
    return 1;
  }
  else
  {
    NFAIL("Search what?\n");
    return 0;
  }
}

string check_floor()
{
  if (shifted)
    return "There is a large gaping\n"+
           "    hole in the floor.\n";
  else
    return "\n";
}

string check_hole()
{
  if (shifted)
    return
"This is a large, black hole.  You do not know where it leads to just yet.\n"+
"But, you can imagine that it goes down..";
  else
    return "You see nothing of interest";
}

int _shift(string str)
{
  if (str == "rock" || str == "large rock" || str == "larger rock")
  {
    if (!searched)
    {
      write("You are not sure exactly which rock you should try and shift.\n"+
	    "Perhaps a closer search of the rocks would give you a \n"+
	    "better idea.\n");
      return 1;
    }
    if (((TP->STR) + (TP->DEX))/2 < 15)
    {
      write("You try and try, but fail to shift the large rock.\n");
   	say(TPN+" shows "+TP->QPOS+" weakness by not being able to shift\n"+
	    "the large rock on the floor.\n");

      return 1;
    }
    if (shifted)
    {
      write("You shift the rock back across the hole in the floor.\n");
	say(TPN+" shifts the large rock so that it covers the \n"+
            "hole in the floor.\n");

      shifted = 0;
      return 1;
    }
    write("You push with all your might, and manage to shift the rock\n"+ 
          "across the floor.  You can then see that there is a large hole\n"+
	  "leading downwards.  Perhaps you could enter it?\n");
      say(TPN+" shifts a rock across the floor of the tunnel.\n"+
	  TP->QPRO+" has just revealed a hole in the floor !!\n");

    shifted = 1;
    return 1;
  }
  else
  {
    NFAIL("Shift what?\n");
    return 0;
  }
}

int _enter(string str)
{
  if (str == "hole")
  {
    if (!shifted)
    {
      write("You cannot do that yet !!\n");
      return 1;
    }
    write("You squeeze yourself through the hole in the floor.\n"+
	  "You start to feel yourself moving...\n\n"+
	  "				...moving...\n\n\n"+
	  "				    ...moving\n\n\n");
      say(TPN+" enters a hole in the floor.\n");

    MPL("downwards.#/players/tamina/castle/planes/earth/rm7");

    return 1;
  }
  else
  {
    NFAIL("Enter what?\n");
    return 0;
  }
}

int faller()
{
  TRM (TO,
   "\nA large boulder falls from the ceiling !!\n"+
   "It just misses you by a whisker...\n");

  return 1;
}

