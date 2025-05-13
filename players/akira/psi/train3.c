inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("In a small training room");
long_desc=("This is one of the many training rooms used by the students\n"+
           "that live here in the tower. At the far end of the room are\n"+
           "what look to be small targets. Here a student learns to focus\n"+
           "thire thoughts into a bolt of force. The walls behind the\n"+
           "targets prove than not everyone is a good shot.\n");
items=({"targets", "The students shot at them to get better",
        "walls", "They all are covered in dents"});
clone_list=({1, 3, "student", "/players/akira/mobs/student", 0,
            1, 1, "subject", "/players/akira/mobs/subject", 0});
::reset(tick);
replace_program("room/room");
dest_dir=({"/players/akira/psi/hall4", "west",
           "/players/akira/psi/stairs", "northwest"});
}
