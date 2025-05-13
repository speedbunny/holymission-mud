inherit "room/room";

void reset(int arg){

if (arg) return;

set_light(1);
short_desc="In the woods";
long_desc=("\
\n\
  This section of the woods is the main hunting grounds for the Zalpurs. \n\
  Zalpur tracks are all over the place.  You see marks where poor, suffering\n\
  animals have squirmed about on the ground writhing with immense pain. \n\
\n\
");


dest_dir=({"players/iishima/area/rooms/val5","southwest",
           "players/iishima/area/rooms/val7","northwest"});


clone_list = ({ 1, 2, "hunter", "players/iishima/area/monsters/zalhunt", 0,
               -1, 1, "staff", "players/iishima/area/weapons/zalstaff.c", 0,
               -1, 1, "jacket", "players/iishima/area/armor/zaljacket.c", 0 });

::reset(arg);
replace_program("room/room");
}
