/*  This is around the Castle Walls  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
  if (arg) return ;

      	set_light(1);
	short_desc = "At the Castle Walls ";
	long_desc = 
"You walk round the walls of the castle, following the path of \n"+
"the moat.  Below you is quite a drop into the murky water of the moat,\n"+
"over the bank on which you stand.  You do not think that anyone would\n"+
"be foolish enough to jump into the moat from here...\n"+
"To the south from here, you can the Dread Forest, where novice Knights\n"+
"are tested before being allowed to join the famous Round Table company.\n";

	dest_dir = ({
          FOREST + "rm3","south",
          CROOMS + "wall21","east",
          CROOMS + "draw_bridge","west",
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
    MPL("into the moat#/players/tamina/castle/rooms/moat2");

    HIT(45);

    return 1;
  }
  else
  {
    NFAIL("Jump where?\n");
    return 0;
  }
}
