/*  This is the West Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";
int searched;

reset(arg) {
  searched = 0;
  if (arg) return ;

      	set_light(0);
	short_desc = "West Wing ";
	long_desc = 
"On taking the smaller passage into the West Wing of the castle Camelot,\n"+
"you realise that the smell from the previous corridor has dissipated in\n"+ 
"here.  In this cramped, and littered corridor, you can see small piles\n"+
"of broken wood, and the occasional rusty iron basket leaning against\n"
"against the wall.  On the wall itself, you can see empty torch-braces\n"+
"looking very old, and rusty.\n";

	dest_dir = ({
          CROOMS + "wcorridor","east",
          CROOMS + "wwing3","north",
         });

        smell = "The air smells musty and cold here";

	items = ({
  "wood",
"These are lying under the braces on the wall, and could indeed be old "+
"torches that have long lost their ability to catch flame",
  "basket",
"This is what would have been a brazier holding hot coals for heating the "+
"corridors of Camelot when it was populated",
  "brace",
"This is a rusty iron bracket atttached to the walls, where the wooden "+
"torches would have been held",
  "piles",
"These are lying under the braces on the wall, and could indeed be old "+
"torches that have long lost their ability to catch flame",
     });

}
init() {
  ::init();
  add_action("search","search");
}

int search (string str) 
{
  object thing;

  if (str == "wood" || str == "piles")
  {
    if (searched) 
    {
      write("You search through the wood, and find nothing.\n");
      say(TPN+" throws the pieces of wood all over the corridor.\n");
      return 1;
    }
    write("You manage to find a scroll in amongst the wood!\n");
    say(TPN+" pulls out a scroll from the wood!\n");

    thing = CLO(COBJ + "scroll2");
    TR(thing, TP);

    searched = 1;
    return 1;
  }
  else
  {
    NFAIL("Search what?\n");
    return 0;
  }
}
