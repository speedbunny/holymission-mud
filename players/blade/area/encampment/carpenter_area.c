inherit "room/room";

#include "/players/blade/area/blade_defs.h"
#include ROOM_FUNCTS
#define FPATH "/players/blade/area/rooms/"

reset(arg) {
  int mon_numbers;

    if(!arg) {
        set_light(1);
        short_desc="The woodworking shop and lumber storehouse",
        long_desc=
"Here wooden supports are fashioned from timber cut from the surrounding\n"+
"hillsides.  Tool handles, benches, carts and additional gutter track are\n"+
"also constructed here.  A small office exists in the northwest corner for\n"+
"the on-duty carpenters to relax between assignments.  Inside the office\n"+
"are two couches, four chairs, a long table, a small end table, and shelves\n"+
"on the west wall.  Plans are nailed up on the wall.\n";
   dest_dir=({
            CAMPPATH+"encampment7.c", "north",
                 });
   items=({ 
   "supports","Large wooden posts that are used to support constructs",
   "timber","Fresh timber that is still a little green",
   "handles","Plain wooden handles",
   "benches","Some unfinished benches lie in the corner",
   "carts","There dont seem to be any carts here now",
   "gutter track","A small lenght of gutter track newly constructed",
   "office","A small office for on-duty carpenters",
   "plans","A bunch of plans to used to make various wooden objects",
   });

        smell = "You smell freshly cut wood.";
    }
    mon_numbers=(2-(filter_live(this_object(),"wolfen carpenter")));
    clone_x_of_y(mon_numbers,"/players/blade/area/monsters/wolfen_carpenter");
}







