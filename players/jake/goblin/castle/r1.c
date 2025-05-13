#include "/obj/door.h"

inherit "room/room";
object obj_1,obj_2,key,dragon;
reset (arg) {
if (!dragon) {
dragon=clone_object("players/jake/goblin/castle/monsters/dragon");
transfer(dragon,this_object());
}
if (!present("door")) {
MAKE_DOORS("players/jake/goblin/castle/r1","north","players/jake/goblin/castle/r2","south","metal","key","A steel door.\n",1,1,1);
}
if(!present("key")) {
MAKE_KEY(key,"metal","key");
move_object(key,dragon);
}
if (arg) return;
set_light(2);
short_desc = "dragon room w/door";
long_desc = "The room looks empty.\n"
+ "The floor is made of bright red stone.\n"
+ "You can see smoke in the room.\n";
dest_dir = ({"players/jake/goblin/castle/c3","south",
});
}
