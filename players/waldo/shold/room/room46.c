#include "/players/waldo/defs.h"
inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    set_light(1);
    short_desc="Cleric's Office.";
    long_desc=
    "In this room you see a polished circular table, fur-lined bench, desk\n"+
    "and a chair, all of which give the room a civilised look and feel. An\n"+
    "elaborate candelabra, made from silver, rests on the table.\n";

    dest_dir=({
    STRONGHOLD+"/room/hall31","north",
             });

    }
  }

init()
{
  ::init();
  return 1;
  }
