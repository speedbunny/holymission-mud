inherit "room/room";

object dragon;

void reset(int arg){
if (arg) return;
set_light(1);
short_desc="Lamtrashara's Den Entrance";
long_desc=("\
\n\
  You have entered the den of Lamtrashara.  A huge guard is standing here,\n\
  watching over the entrance to Lamtrashara's den. \n\
\n\
");
dest_dir=({"players/iishima/area/rooms/realm8","north",
           "players/iishima/area/rooms/realm6","out"});


clone_list = ({ 1, 1, "dragon", "players/iishima/quest/dguard", 0 });
::reset(arg);
replace_program("room/room");
}
