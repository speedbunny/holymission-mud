inherit "room/room";

#include "/players/tatsuo/area/tatsuo_defs.h"
#include ROOM_FUNCTS

int ran_monsters;

reset(arg) {
  int i,temp;
    if(!arg) {
      ran_monsters=random(7);
        set_light(1);
        short_desc="A dense forest";
        long_desc=
"You are surrounded by large trees, and much leafy green foliage.\n"+
"Noises come from all around you, and you feel watched.\n";

   dest_dir=({
            F1PATH+"forest30.c","north",
            F1PATH+"forest28.c","northeast",
	    F1PATH+"forest35.c","west",
     });
   items=({ 
     "palisade","A large palisade with a wolfen guard standing on top",
     "trees","Large trees surrounding you",
     "foliage","Green foliage of all types",
     "valley","Mountains rise up on either side of a small valley",
     "mountains","Steep mountains that rise in the north and the south",
   });

        smell = "You smell nothing special.";
    }
temp=(ran_monsters-(filter_monster(this_object())));
for(i=0;i<temp;i++){
  move_object((clone_object(MPATH+"forest_monster.c")),this_object());
}

}


