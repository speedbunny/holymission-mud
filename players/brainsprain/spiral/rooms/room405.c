inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Goblin Armoury";
  long_desc =
"Racks line the walls of this room.  Bristling off of each shelf are "+
"axes and clubs and various other weapons.  However a chain prevents "+
"any item from being taken.  The floor of the room has stacks of shields "+
"bolted to it.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room404","south",
    sr+"/room406","northwest",
  });
    items = ({
    "shelf",
    "Shelves containing stacks of weapons",
    "racks",
    "Racks comtain stacks of weapons",
    "chain",
    "A thick chain wrapped tightly around all the items",
    "axes",
    "Massive stone axes, chained to the rack",
    "clubs",
    "Massive stone clubs, chained to the rack",
    "weapons",
    "Various weapons that line the racks",
    "shields",
    "A shield bearing the Galgug",
  });
    clone_list = ({ 
       1, 2, "monster", sm+"/goblin_fighter.c", 0,
       2,1, "com",sm+"/goblin_commander.c",0,
    });   
  ::reset(arg);
    replace_program("room/room");
}
