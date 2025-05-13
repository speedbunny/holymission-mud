/*  This is a chest  */

#include "/players/tamina/defs.h"

inherit "obj/container";
int opened;
object sheath;


int _open (string str) 
{
  if (str == "chest" || str == "the chest") 
  {
    if (!opened) 
    { 
      opened = 1;
      write("You open the chest.\n"+
	    "Inside, you see a beautiful scabbard, sitting on\n"+
	    "a sapphire-blue satin cushion.  It sparkles in\n"+
	    "the dim light.\n");
        say(TPN+" opens the chest.\n");
      return 1;
    }
      write("It is already opened!\n");
      say(TPN+" looks like a fool, trying to open an opened chest!\n");
  }
  return 0;
}


void reset(int arg) {
  ::reset(arg);
  if(arg) return;

    set_name("a chest");
    set_alias("chest");
    set_short("A Chest");
    set_long(
"This is a large, sturdy chest, with a solid lock attached to the lid.\n"+
"The lock is made out of some black material.\n");
    set_value(0);
    set_weight(20);
    set_max_weight(5);
    set_can_close(1);
    set_opened(0);
    TR (CLO (COBJ + "sheath"), TO);
}

void init() 
{
    ::init();
    AA("_open",   "open");
}
