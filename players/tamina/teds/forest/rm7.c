inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  if (arg) return 0;

  set_light(1);
  short_desc = "Petrified Forest";
  long_desc =
"You exit the Petrified Forest here, to stand at the moat of\n"+
"the castle, Camelot.  Below you, you can see the murky waters\n"+
"of the moat, into which you think it may be possible to jump...\n";

  dest_dir = ({
    TFOREST + "rm4", "south",
    CROOMS + "draw_bridge", "east"
    });

  items = ({
  "moat",
"A large protective body of water surrounding the castle, Camelot",
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
    write("You scream 'G E R O N I M O O o o o . .'\n\n"+
          "as you jump into the moat.\n");
      say(TPN+" screams something as "+TP->QPRO+" jumps into the moat.\n");
    MPL("into the moat#/players/tamina/castle/rooms/moat3");

    this_player()->hit_player(15, 2, ({ 0 }) );
    return 1;
  }
  else
  {
    NFAIL("Jump where?\n");
    return 0;
  }
}

