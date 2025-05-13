/*  This is around the Castle Walls  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
  if (arg) return ;

      	set_light(1);
	short_desc = "At the Castle Walls ";
	long_desc = 
"You continue along the little trail that winds round the cast walls.\n"+
"You can see the moat far below you now, as the ledge rises up a small \n"+
"slope.  To the south, you can see the more of the Dread Forest, where \n"+
"young novice Knights are tested.\n"; 

	dest_dir = ({
          FOREST + "rm4","south",
          CROOMS + "wall2","west",
        });

	items = ({
  "moat",
"A large body of water surrounding the castle, Camelot, for its "+
"protection against enemies and foes",
  "bank",
"The very large drop from where you stand into the moat itself",
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
    MPL("into the moat#/players/tamina/castle/rooms/moat21");

    HIT(60);

    return 1;
  }
  else
  {
    NFAIL("Jump where?\n");
    return 0;
  }
}
