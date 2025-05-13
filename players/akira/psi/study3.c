inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("In a small study");
long_desc=("This is the study room of the Psi-Master's of the Tower.\n"+
           "The room itself is not all the big, but it is very well\n"+
           "stocked with books. The chair's and desk's are very well\n"+
           "kept along with the rest of the room.\n");
items=({"books", "They are psi-teaching books" });
clone_list=({1, 2, "master", "/players/akira/mobs/master", 0});
::reset(tick);
replace_program("room/room");
dest_dir=({"/players/akira/psi/stairs4", "east" });
}
