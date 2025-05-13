inherit "room/room";
reset(tick){
if(tick)return;
set_light(1);

short_desc=("In a small training room.");
long_desc=("This is another one of the training rooms used by the\n"+
           "students of the mental arts. This room however is not\n"+
           "as nice looking as the other training rooms. There are\n"+
           "what look to be dead bodies chained to the walls. You can\n"+
           "only guess that in this room a students learns to use his\n"+
           "talents to hurt others.\n");
items=({"bodys", "They are dead! Some of them are missing there heads",
        "chains", "They are used to keep the test subject in place",
        "blood", "It covers most of the walls" });
clone_list=({1, 4, "subject", "/players/akira/mobs/subject", 0,
             1, 3, "student" ,"/players/akira/mobs/student", 0,
             1, 1, "master",  "/players/akira/mobs/master", 0});
::reset(tick);
replace_program("room/room");
dest_dir=({"/players/akira/psi/train1", "south",
           "/players/akira/psi/stairs", "east",
           "/players/akira/psi/hall4", "southeast" });
}
