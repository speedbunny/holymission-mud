/*  This is the Guests' Room  */

#include "/players/tamina/defs.h"

inherit "room/room";
int searched;

reset (arg) 
{
  searched = 0;
  if (arg) return;

      	set_light(0);
	short_desc = "Guests' Rooms";
	long_desc = 
"You take the north-west passage, and walk along the dim corridor.\n"+
"At the end of the passage, you can see a set of broken doors \n"+
"hanging at angles from the broken hinges.  When you reach them,\n"+
"you gingerly step over them, not wishing to bring them down on top\n"+
"of yourself.  Here, you find yourself in some sort of suite which, \n"+
"by its smaller size, you assume that it was not used as the personal\n"+ 
"rooms of the King.  Throughout the small room, you can see the \n"+
"remnants of habitation, such as broken beds, rusty basins, and old\n"+
"chests.\n";

	dest_dir = ({
          CROOMS + "reception","southeast",
        });

	items = ({
  "beds",
"These have fallen apart, and not simply because of lack of use, "+
"or age..",
  "bed",
"These have fallen apart, and not simply because of lack of use, "+
"or age..",
  "basins",
"You see that these are full of rust-tinged water, which would not "+
"be pleasant to drink",
  "basin",
"You see that these are full of rust-tinged water, which would not "+
"be pleasant to drink",
  "chests",
"Old boxes made of what was at one time a sturdy wood, but have been "+
"deliberately broken into",
  "chest",
"Old boxes made of what was at one time a sturdy wood, but have been "+
"deliberately broken into",
  "doors",
"These are wooden doors hanging limply from the hinges",
     });

}

init()
{
  ::init();
  AA("_search", "search");
}

int _search(string str)
{
  object candle;

  if (str == "chest"  || str == "chests")
  {
    if (searched)
    {
      write("You do not find anything amongst the heap of broken wood\n"+
	    "that was once a chest...\n");
        say(TPN+" searches through the pile of broken chests.\n");

      return 1;
    }
    write("You search through the wood from the chests, and find an old candle.\n");
      say(TPN+" finds a candle amongst the pile of chests.\n");

    candle = CLO (COBJ + "candle");
    TR (candle, TP);

    searched = 1;
    return 1;
  }
  else
  {
    NFAIL("Search where?\n");
    return 0;
  }
}
