inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A dark hall";
  long_desc =
"The size of the hallway has narrowed to a corridor no more than "+
"seven feet in diameter.  Stalagmites are scattered along the floor. "+
"A massive pillar stands in the middle of this room and makes it very "+
"hard to pass by.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room304","southeast",
    sr+"/room306","northwest",
  });
  items = ({
    "pillar",
    "A natural stone pillar",
    "stalagmites",
    "Watch out or you might trip over them",
  });
clone_list = ({ 
       1, 2, "monster", sm+"/goblin_fighter.c", 0,
       2,1, "monster2",sm+"/goblin_commander.c",0 
    });   
  ::reset(arg);
    replace_program("room/room");
}  

