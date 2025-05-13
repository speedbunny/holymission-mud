inherit "room/room";

#include "/players/tamina/defs.h"

object mordred, powder;
int searched;

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return 0;

      set_light(1);
      short_desc = "Quadrangle";
      long_desc = 
"You are standing in the centre of the Quadrangle, which is situated in\n"+
"the rear of Camelot.  The grass around you is rather unkempt, being\n"+
"long, dishevelled, and full of weeds.  On the far side of the Eastern\n"+
"and Western path-ways, you can see what would appear to be walled-gardens,\n"+ 
"which admittedly look as though they are in a sorry state.  To the north,\n"+ 
"beyond the Northern path, you can see a link heading back into the interior\n"+ 
"of Camelot.\n";

	dest_dir = ({
          CROOMS + "n_cloister","north",
          CROOMS + "s_cloister","south",
          CROOMS + "e_cloister","east",
          CROOMS + "w_cloister","west",
        });

	items = ({
  "grass",
"It is now very long, and full of bindweed, and ground elder",
     });

  searched = 0;
  if (!mordred)
    MO (mordred = CLO (CMONS + "mordred"), TO);
}

void init() 
{
  ::init();
  AA("_search","search");
}

int _search (string str) 
{
  if (!str || str != "grass") 
  {
    NFAIL("You cannot search there.\n");
    return 0;
  }
  if (searched) 
  {
    write("You search through the grass, but find nothing.\n");
    say(TPN+" searches through the grass, but to no avail.\n");

    return 1;
  }
  write("You are lucky enough to have found a strange packet of powder\n"+
	"amongst the long grass...\n");
  say(TPN+" manages to find a packet amongst the grass.\n");

  powder = CLO (COBJ + "powder");
  TR (powder, TP);

  searched = 1;
  return 1;
}
