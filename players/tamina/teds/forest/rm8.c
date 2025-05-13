inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  if (arg) return 0;

  set_light(1);
  short_desc = "Petrified Forest";
  long_desc =
"You are standing at the bank of the moat to the castle, Camelot.\n"+
"To your south is the dreaded Petrified Forest.  The moat over\n"+
"the bank looks very far below...quite a drop.\n";

  dest_dir = ({
    TFOREST + "rm5", "south",
    CROOMS + "draw_bridge", "west"
    });

  items = ({
  "moat",
"A large body of water providing protection to Camelot against "+
"her enemies",
  "banks",
"It is a very large drop down into the moat.  You don't think anyone "+
"would be so stupid to try and jump down there.."
  });

}

void init()
{
  ::init();
  AA("_jump", "jump");
}

int _jump(string str)
{
  if (str == "into the moat" || str == "into moat" || str == "moat" ||
        str == "water" || str == "into water" || str == "into the water")
  {
    write("You scream:\n"+
          "      'G E R O N I M O O o o o . .'\n\n"+
          "as you jump into the moat.\n");
      say(TPN+" screams something as "+TP->QPRO+" jumps into the moat.\n");
    MPL("into the moat#/players/tamina/castle/rooms/moat2");

    this_player()->hit_player(35, 2);
    return 1;
  }
  else
  {
    NFAIL("Jump where?\n");
    return 0;
  }
}

