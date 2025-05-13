/*  This is the first Water Room  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
  if (arg) return ;

      	set_light(1);
	short_desc = "Elemental Plane of Water";
	long_desc = 
"    You have just entered the "+short_desc+".\n"+
"    You are standing on what would appear to be a solid bed of sea-weed,\n"+ 
"    which stretches out before you to the south for as far as you can\n"+
"    see at the moment.  Below this wavering pathway is the sea-bed, a \n"+
"    vast surface of eroded rock, covered in all manner of sea plantlife.\n"+
"    North of you can be seen vast structures of where the sea-bed has\n"+
"    thrust up its surface into all manner of shapes.  In the west there\n"+
"    can be seen man dangerous currents and maelstroms that could easily\n"+
"    sweep you anywhere...  To the east you can see very little, as there\n"+
"    is a great cliffside that rises up to the water-surface which you\n"+
"    presume to be above you somewhere.  And in the south, you can see\n"+
"    just the simple continuation of the walkway of sea-weed.\n";
	no_obvious_msg = "\n";

	property = ({"has_water", "no_teleport"});

	items = ({
  "pathways",
"It is constructed entirely from sea-weed, but apart from this, you think "+
"they look fairly stable, and would hold your weight easily",
  "walkway",
"It is constructed entirely from sea-weed, but apart from this, you think "+
"they look fairly stable, and would hold your weight easily",
  "air", 
"There is no air here!",
  "sea-bed",
"A great rollling surface of rock, covered in many plants and indeed many "+
"sea animals",
  "structures",
"You cannot exactly see what these structures are supposed to be from where "+
"you are at the moment... You would have to go investigate them closer",
  "currents",
"Well, you can't exactly look at currents, but you can see the turbulence "+
"they are creating in that direction",
  "maelstroms",
"Great funnels of turbulent water that spin madly in wide arcs.  You "+
"definitely would not want to go there",
  "cliff",
"It is far too steep (almost vertical) so you are not going to climb it",
     });

}

init() 
{
  ::init();
  AA("go_north", "north");
  AA("go_south", "south");
  AA("go_east",  "east");
  AA("go_west",  "west");
  AA("_climb",   "climb");
  if (!present("pipe", TP)) 
  {
    write(
  "This is the "+short_desc+".\n"+
  "But you are starting to get short of breath!!\n"+
  "You suddenly feel that you should not have ventured here without\n"+ 
  "adequate protection from the elements...You start to drown!!\n");
    say(
  TPN+" suddenly starts to turn a distinctly dangerous shade of pink...\n"+ 
  "which turns to red...which turns to purple..."+TPN+"'s face starts to \n"+ 
  "expand unnaturally!!\n"); 

    HIT(75);

    MPL("in a great bubble of gaseous air!#/players/tamina/castle/rooms/p_2");

    return 1;
   }

}

int go_north()
{
  write("You paddle your way north.\n");
  MPL("paddling north.#/players/tamina/castle/planes/water/struc");

  return 1;
}

int go_south()
{
  write("You paddle your way south.\n");
  switch(random(6))
  {
    case 0:
      MPL("paddling southwards.#/players/tamina/castle/planes/water/rm2");
      break;
    case 1 .. 3:
      MPL("paddling southwards.#/players/tamina/castle/planes/water/rm3");
      break;
    default:
      MPL("paddling southwards.#/players/tamina/castle/planes/water/rm2");
      break;
  }
  return 1;
}

int go_east()
{
  write("There is a cliff in that direction, which you promptly walk into !\n");
    say(TPN+" walks into the cliff to the east !!\n");

  HIT(5);

  return 1;
}

int go_west()
{
  write("You swim to the west.\n");
  MPL("paddling west.#/players/tamina/castle/planes/water/mael1");
 
  return 1;
}

int _climb(string str)
{
  if (str == "cliff")
  {
    write("You only make it up a few feet before you fall back down to\n"+
	  "the sea-weed pathway.\n");
      say(TPN+" tries rather stupidly to climb the cliff...\n");

    HIT(12);

    return 1;
  }
  else
  {
    NFAIL("Climb where?\n");
    return 0;
  }
}


