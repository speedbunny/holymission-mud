inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("A Small Training Room.\n");
long_desc=("You are standing in a small traing room used by new\n"+
           "students of the mental arts. In rooms like this they\n"+
           "learn how to lift objects with there minds. There are\n"+
           "many rocks on the floor, you can guess they practice\n"+
           "lifting them.\n");
items=({"rocks", "They are nothing special"});
clone_list=({1, 2, "student", "/players/akira/mobs/student", 0});
::reset(tick);
replace_program("room/room");
dest_dir=({"/players/akira/psi/train2", "north",
           "/players/akira/psi/hall4", "east",
           "/players/akira/psi/stairs", "northeast"});
}
