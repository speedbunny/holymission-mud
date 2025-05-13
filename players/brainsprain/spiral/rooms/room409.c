inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Stone columns";
  long_desc =
"Ornate stone columns line the hallway.  Two suits of platemail stand "+
"guard in front of the southwestern doorway.  High-picked clicking noises "+
"come from the southwest. Several pieces of cloth lie here and there on "+
"the floor.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room410","southwest",
    sr+"/room408","northeast",
  });
items = ({
  "cloth",
  "The remains of a shirt",
  "columns",
  "Huge stone columns that appear more ornamental that supportive",
  "platemail",
  "Empty platemail guards, however you feel as though they are best left alone",
      });
clone_list = ({ 
       1, 2, "monster", sm+"/goblin_fighter.c", 0,
        });   
  ::reset(arg);
    replace_program("room/room");
}

