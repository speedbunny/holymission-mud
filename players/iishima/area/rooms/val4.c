inherit "room/room";

void reset(int arg){

if (arg) return;
set_light(1);
short_desc="In the woods";
long_desc=("\
\n\
  Back to the west you can see the start of the Zalpur's hunting grounds. \n\
  This wooded area is so dense that you can barely see.  You hear evil --\n\
  inhuman sounds comming from the northeast and the south east. \n\
\n\
");
         
dest_dir=({"players/iishima/area/rooms/val3","west",
           "players/iishima/area/rooms/val7","northeast",
           "players/iishima/area/rooms/val5","southeast"});


::reset(arg);
replace_program("room/room");
}
