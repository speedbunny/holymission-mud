inherit "room/room";
void reset(int arg){

if (arg) return;
set_light(2);
short_desc="In a small town";
long_desc=("\
\n\
  Back to the east you can see the start of the Zalpur's hunting grounds. \n\
  You have enter the Zalpur town.  Many people are strolling about. \n\
\n\
");
         
dest_dir=({"players/iishima/area/rooms/val3","east",
           "players/iishima/area/rooms/val10","southwest"});


clone_list = ({ 1, 2, "peasant", "players/iishima/area/monsters/zalpeas", 0,
               -1, 1, "shovel", "players/iishima/quest/shovel", 0 });

::reset(arg);
replace_program("room/room");
}

