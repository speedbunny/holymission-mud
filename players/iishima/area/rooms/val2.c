inherit "room/room";

void reset(int arg){

if (arg) return;
set_light(1);
short_desc="In the woods";
long_desc=("\
\n\
  You have just entered the outskirts of Zalpur Valley.  Your stomach twists\n\
  and turns as the smell of fear mixes with the smell of death.  Many evil\n\
  sounds are comming from all around.  The only human sound that can hear,\n\
  other than your teeth chattering, is the sound of people being tortured. \n\
\n\
");
         
dest_dir=({"players/iishima/area/rooms/val3","north",
           "players/iishima/area/rooms/val1","south"});

clone_list = ({ 1, 2, "peasant", "players/iishima/area/monsters/zalpeas", 0,
               -1, 1, "shovel", "players/iishima/quest/shovel", 0 });

::reset(arg);
replace_program("room/room");
}
