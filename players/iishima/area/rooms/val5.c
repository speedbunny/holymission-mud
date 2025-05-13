inherit "room/room";

void reset(int arg){

if (arg) return;
set_light(1);
short_desc="In the woods";
long_desc=("\
\n\
  This section of the woods is the main hunting grounds for the Zalpurs. \n\
  This is their main source of food, other than humans.  You get an uneasy\n\
  feeling as you see the heads and skeletons of animals. \n\
\n\
");
         
dest_dir=({"players/iishima/area/rooms/val4","northwest",
           "players/iishima/area/rooms/val6","northeast"});

clone_list = ({ 1, 1, "hunter", "players/iishima/area/monsters/zalhunt", 0,
               -1, 1, "staff", "players/iishima/area/weapons/zalstaff.c", 0,
               -1, 1, "jacket", "players/iishima/area/armor/zaljacket.c", 0,
                2, 1, "wolf", "players/iishima/area/monsters/wolf", 0 });

::reset(arg);
replace_program("room/room");
}
