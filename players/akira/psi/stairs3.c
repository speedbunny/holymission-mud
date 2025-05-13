inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("Next to a flight of stairs");
long_desc=("You are standing next to a small flight of stairs that\n"+
           "lead to the next level of the tower. There is something\n"+
           "about this flight of stairs that you just do not like.\n");
items=({"stairs", "They seem cold and dark, almost evil"});
clone_list=({1, 2, "guard","/players/akira/mobs/guard", 0});
::reset(tick);
replace_program("room/room");
dest_dir=({"/players/akira/psi/hall6", "south",
           "/players/akira/psi/stairs4", "up" });
}
