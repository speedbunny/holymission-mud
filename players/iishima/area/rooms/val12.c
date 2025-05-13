inherit "room/room";

void reset(int arg){

if (arg) return;
set_light(2);
short_desc="In a small town";
long_desc=("\
\n\
  This is the main part of the town.  Many people are strolling about.  Many\n\
  people come here to pay homage to their masters.  To the north is the\n\
  Knight's Quarters.  A sense of peacefullness engulfs you as you look around\n\
  the small, quiet town. \n\
\n\
");
         
dest_dir=({"players/iishima/area/rooms/val13","west",
           "players/iishima/area/rooms/val11","east",
           "players/iishima/area/rooms/val14","north"});


clone_list = ({ 1, 1, "peasant", "players/iishima/area/monsters/zalpeas", 0,
               -1, 1, "shovel", "players/iishima/quest/shovel", 0 });
::reset(arg);
replace_program("room/room");
}

