/* featuring a large boa constrictor with info */
inherit "room/room";

void reset(int arg) {
   if(arg) return 0;

   set_light(1);
   short_desc="Somewhere in the jungle";
   long_desc="Here in the middle of the jungle you find a pool of dark "
           + "water. Surrounding the pool stand some big palmtrees. "
           + "Although you still don't know where you are, at least "
           + "this is a place where you can rest. \n";
   dest_dir=({"/players/uglymouth/vikings/infjungle3","jungle", });
   items=({"pool","A murky pool of water",
           "water","It looks dark but clear",
           "palmtrees","Some coconuts grow in them", });
   smell="Cool but humid air fills your nose with a herbal scent. \n";

   replace_program("room/room");
   }
