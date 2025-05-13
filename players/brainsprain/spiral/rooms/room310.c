inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A dark hall";
  long_desc =
"A huge set of double doors lies open to the south.  A relief carving on "+
"them depicts an impossibly tall man wielding a staff as minions of goblins "+
"  watch him in adoration.  The sound of distant drums beating bounce off "+
"The walls of the room.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room309","northeast",
    sr+"/room311","south",
  });
  items = ({
    "doors",
    "Thankfully they stand open for they would be impossible to move",
    "carving",
    "A carving of Darkstaff, the lord of the cavern",
      });
    clone_list = ({ 
       1, 3, "monster", sm+"/goblin_fighter.c", 0,
    });   
  ::reset(arg);
    replace_program("room/room");
}

