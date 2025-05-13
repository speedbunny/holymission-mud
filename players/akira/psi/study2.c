inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("Study Room");
long_desc=("This is one of the student's study rooms. There are many\n"+
           "desks against the halls, and a large table in the middle\n"+
           "of the room. The room itself is a mess, papers all over the\n"+
           "place. You can only guess what happens when a psionicist\n"+
           "student gets a stress attack.\n");
items=({"table", "This is group study table",
        "desks", "They are for private study" });
dest_dir=({"/players/akira/psi/hall5", "west" });
}
