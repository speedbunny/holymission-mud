inherit "room/room";

void reset(int arg){

if (arg) return;
set_light(1);
short_desc="Lamtrashara's Den";
long_desc=("\
\n\
  You have entered the den of Lamtrashara.  You see blood and tortured bodies\n\
  everywhere.   You do not want to mess with Lamtrashara.  PREPARE TO DIE!\n\
\n\
");

dest_dir=({"players/iishima/area/rooms/realm7","south"});
clone_list=({1,1,"dragon","players/iishima/area/monsters/lamtrashara",0});
::reset(arg);
replace_program("room/room");
}
