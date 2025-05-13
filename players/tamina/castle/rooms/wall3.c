/*  This is around the Castle Walls  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
  if (arg) return ;

      	set_light(1);
	short_desc = "At the Castle Walls";
	long_desc = 
"You walk round the walls of the castle, following the path of \n"+
"the moat.  Below you, you can see the murky water of the moat,\n"+
"over the bank on which you stand.  You think that it is possible\n"+
"to jump into the moat from here, but it is quite a drop still...\n";

	dest_dir = ({
   	  FOREST + "rm2", "south",
          CROOMS + "draw_bridge","east",
          CROOMS + "wall31","west",
        });

	items = ({
  "moat",
"A large body of water surrounding the castle, Camelot, for its "+
"protection against enemies and foes",
  "bank",
"The small drop from where you stand into the moat itself",
  "walls",
"You can see walls of the castle, Camelot from here.  They do not look "+
"as in good condition as you have known from legends...Perhaps something "+
"is afoot here",
     });

}

init() 
{
  ::init();
  AA("_jump",  "jump");
}

int _jump(string str)
{
  if (str == "into moat" || str == "moat" || str == "into the moat" ||
	str == "the moat" || str == "water")
  {
    write("You scream: G E R O N I M O O O o o o !!\n\n"+
	  "as you jump off the bank and land in the moat with a huge\n\n"+
	  "         * * * S P L A S H * * *\n\n");
      say(TPN+" screams: G E R O N I M O O O o o o !!\n\n"+
	  "as "+TP->QPRO+" jumps off the bank !!\n");
    MPL("into the moat#/players/tamina/castle/rooms/moat3");

    HIT(15);

    return 1;
  }
  else
  {
    NFAIL("Jump where?\n");
    return 0;
  }
}
