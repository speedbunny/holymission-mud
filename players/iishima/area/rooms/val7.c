inherit "room/room";

void reset(int arg){
if (arg) return;
set_light(2);
short_desc="In the woods";
long_desc=("\
\n\
  This section of the woods is the main hunting grounds for the Zalpurs. \n\
  This is their main source of food, other than humans.  You see the corpses\n\
  of many tortured animals.  A body of a deer lies here.  It has been slain\n\
  and its entrails have been savagly removed from its body.  A sick feeling\n\
  comes over you upon seeing this horrible site. \n\
\n\
");
         

dest_dir=({"players/iishima/area/rooms/val4","southwest",
           "players/iishima/area/rooms/val6","southeast",
           "players/iishima/area/rooms/val8","north"});

clone_list = ({ 1, 1, "hunter", "players/iishima/area/monsters/zalhunt", 0,
               -1, 1, "staff", "players/iishima/area/weapons/zalstaff.c", 0,
               -1, 1, "jacket", "players/iishima/area/armor/zaljacket.c", 0 });
::reset(arg);
replace_program("room/room");
}

