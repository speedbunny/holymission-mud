/*  This is the Bottom of a Well */

#include "/players/tamina/defs.h"

inherit "room/room";
status pulled_down;

reset(arg) {
  if (arg) return ;

      	set_light(-1);
	short_desc = "Bottom of a Well";
	long_desc = 
"You stand knee-deep in slimy water at the bottom of a well.\n"+
"The is a strong odour of slime, and algae all around you.\n"+
"Lichen hangs to the walls in great clumps, which glow unnaturally.\n"+
"Here, you can only see a circular wall around you, and a rope\n"+
"hanging up the well, with the bucket attached to it.\n";
	no_obvious_msg = "\n";

	items = ({
  "water",
"It is coloured black here, and swirls in inky circles around your feet",
  "wall",
"A well crafted circular wall that goes around you.\n"+
"You do notice however that there is a very small, dark hole at the "+
"level of the water",
  "lichen",
"Clumps of glowing algae that don't look very safe",
  "rope",
"You just climbed down it",
  "bucket",
"A large, iron bucket hanging from a rope, full of inky-black water",
  "hole",
"You think only a very small person could fit in here",
     });

}

init() {
  ::init();
  add_action("pull_rope","pull");
  add_action("climb_up","climb");
  add_action("get_lichen","get");
  add_action("get_lichen","take");
  add_action("enter_hole","enter");
}

int pull_rope (string str) 
{

  if (str != "rope")
  {
    NFAIL("What do you want to pull?\n");
    return 0;
  }
  if (TP->STR > 30) 
  {
    write("Your strength is such that you pull down the rope\n"+
          "from the top of the well!!  It lands on your head!\n");
    say(TPN+" brings the rope down on top of his head!\n");

    HIT(15);

    pulled_down = 1;

    return 1;
  }
  write("You cannot pull the rope down, since it is attached to\n"+
        "the top of the well!\n");
  say(TPN+" tries to pull the rope when it is already lowered!\n");

  return 1;

}

int climb_up (string str) 
{
  if (str == "rope")
  {
    if (pulled_down) 
    {
      write("How are you going to do that?\n"+
            "The rope has been pulled down!!\n");
      say(TPN+" tries to climb up an imaginary rope!\n");

      return 1;
    }
    if ( (TP->DEX + TP->STR) /2 < 20) 
    {
      write("You only manage to make it up half way, before\n"+
            "you plummet back down to land with a huge Splash!!\n");
      say(TPN+" tries to climb back up the rope, but only manages\n"+
          "half way, before falling back into the water with a Splash!!\n");

      return 1;
    }
    write("You climb back up the rope.\n");
  
    MPL("back up the rope#/players/tamina/castle/rooms/court2");

    return 1;
  }

}

int get_lichen (string str) 
{
  if (str == "lichen") 
  {
    write("As you touch the glowing lichen on the walls, your fingers\n"+
          "start to burn, and freeze, and sizzle!!\n\n"+
          "You let go immediately!\n");
    say(TPN+" looks in amazement at the lichen on the walls!\n");

    HIT(35);
  
    return 1;
  }
}

int enter_hole (string arg) 
{
  if (arg == "hole") 
  {
    if (TP->query_size() != 1) 
    {
      write("You are too large to enter here!\n");
      say(TPN+" desperately tries to squeeze into the hole!\n");
    }
    else 
    {
      write("You jump through the hole very easily!\n");
      MPL("through the hole#/players/tamina/castle/rooms/well2");
    }
    return 1;
  }

}
