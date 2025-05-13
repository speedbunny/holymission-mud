inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("Meeting Hall");
long_desc=("This is the meeting hall of the Psi-Masters. A large table\n"+
           "stands in the middle of the room. In here the master's deside\n"+
           "what students should be let into the tower to learn the mental\n"+
           "arts. The room looks to be very well lit.\n");
items=({"table", "This is a huge table were the Psi-Master's meet" });
clone_list=({1, 3, "master", "/players/akira/mobs/master", 0});
::reset(tick);
replace_program("room/room");
dest_dir=({"/players/akira/psi/hall7", "west" });
}
