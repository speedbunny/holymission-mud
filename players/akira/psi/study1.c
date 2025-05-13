inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("Study Room");
long_desc=("This is one of the student's study rooms. There are many\n"+
           "desks against the halls, and a large table in the middle\n"+
           "of the room. This place looks like it is used a lot.\n");
items=({"table", "This is group study table",
        "desks", "They are for private study" });
clone_list=({1, 2, "student", "/players/akira/mobs/student", 0});
::reset(tick);
replace_program("room/room");
dest_dir=({"/players/akira/psi/hall6", "west" });
}
