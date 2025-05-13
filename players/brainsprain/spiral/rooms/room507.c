inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Orcish barracks";
  long_desc =
"Straw pallets lay all over the floor.  In the corner sits a well.  "+
"Various odds and ends of orcish personal equipment lays around.  "+
"On a whole the rooms smells of swear and other excretions.\n";
   set_light(1);
    dest_dir = ({
    sr+"/room506","southeast",
    sr+"/room508","northwest",
  });
  items =({
    "pallets",
    "Grimy hunks of straw",
    "well",
    "A well filled with stagnant water with algae on top",
    "equipment",
    "Pieces of broken plates and bent forks",
 });
    clone_list = ({ 
       1, 1, "monster", sm+"/orc_guard.c", 0,
        });
  ::reset(arg);
    replace_program("room/room");
}
