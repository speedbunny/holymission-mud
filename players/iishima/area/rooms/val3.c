inherit "room/room";

void reset(int arg){

if (arg) return;
set_light(1);
short_desc="In the woods";
long_desc=("\
\n\
  You are hear many strange sounds.  This is the main hunting area of the\n\
  Zalpurs.   As you walk through the forest, you see many slaughtered animals\n\
  and signs of hunters that are close by.  It is so dark that you can barely\n\
  see the trail behind you. \n\
\n\
");
          
         
dest_dir=({"players/iishima/area/rooms/val4","east",
           "players/iishima/area/rooms/val9","west",
           "players/iishima/area/rooms/val2","south"});

clone_list = ({ 1, 1, "hunter", "players/iishima/area/monsters/zalhunt", 0,
               -1, 1, "staff", "players/iishima/area/weapons/zalstaff.c", 0,
	       -1, 1, "jacket", "players/iishima/area/armor/zaljacket.c", 0,
                2, 2, "peasant", "players/iishima/area/monsters/zalpeas", 0,
               -2, 1, "shovel", "players/iishima/quest/shovel", 0 });
::reset(arg);
replace_program("room/room");
}
