inherit "room/room";

#include "/players/blade/area/blade_defs.h"
#include ROOM_FUNCTS
int ran_monsters;

reset(arg) {
  int mon_numbers;
    if(!arg) {
      ran_monsters=random(3);
      set_light(0);
      short_desc="A tunnel in the mine";
      long_desc=
"A dark tunnel hewn from stone.  It extends into the darkness.  Gravel\n"+
"crunches underfoot, and you have to struggle not to twist an ankle on\n"+
"some of the larger stones.  It is unnaturally quiet.  Cart tracks extend\n"+
"across the room going east and west.\n";
   dest_dir=({
            L1PATH+"mt8.c",   "west",
	    L1PATH+"mt6.c",   "east",
	  });
   items=({ 
     "stone","Cold dark stone that has been chipped all over",
     "gravel","Sharp stone that crunches underfoot",
     "larger stones","It looks big enough to trip over",
     "tracks","Tracks used to push carts along",
     "tunnel","A tunnel hewn from stone",  
   });

        smell = "You dont smell anything special";
      }
    mon_numbers=(ran_monsters-(filter_live(this_object(),"slave")));
    clone_x_of_y(mon_numbers,"/players/blade/area/monsters/slave.c");
}










