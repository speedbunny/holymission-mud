inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("In a small hall");
long_desc=("This is a very small hallway. There is a door to the south\n"+
           "and to the east.\n");
clone_list=({1, 1, "guard", "/players/akira/mobs/guard", 0});
::reset(tick);
replace_program("room/room");
dest_dir=({"/players/akira/psi/stairs4", "north",
           "/players/akira/psi/master", "south",
           "/players/akira/psi/meet", "east" });
}
