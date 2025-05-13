#include "/players/waldo/defs.h"

inherit "room/room";

reset (arg)
{
  if (!arg)
  {
    set_light(0);
    short_desc="Inside the cave";
    long_desc=
	"You stand somewhere in the huge cave system. A faint\n"+
	"glow is reflected from the walls. You sense an eerie\n"+
	"feeling about the place.\n"+
	"You notice a circle of runes on the floor.\n";

    dest_dir=({
      MYAREA+"/room/l68","north",
	});

    items=({
          "circle","Perhaps you can ENTER it",
          "runes","Weird arcane lettering which you cant understand",
	});
    }
  }

init()
{
  ::init();
  AA("_enter","enter");
  }

_enter(str)
{
  if ( (!str) || (str!="circle") || (str!="runes") )
     NF("Enter what ?");
  TELLRM(ENV(TP),CAP(TPRN)+" enters the circle and vanishes.\n");
  transfer(TP,MYAREA+"/room/l11");
  command("look",TP);
  return 1;
  }
