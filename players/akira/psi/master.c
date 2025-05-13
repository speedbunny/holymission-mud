inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("The Psi-Lords Chambers");
long_desc=("This is the living area for the Psi-lord of the Tower of\n"+
           "Highest Thought. The room is huge, and covered in books.\n"+
           "Aside from the bed and a small desk, the room has about\n"+
           "five book shelves. Too be the Lord of this Tower you must\n"+
           "smart as well as strong.\n");
items=({"books", "They seem to be on just about any topic",
        "shelves", "They line the walls of the room",
        "bed", "It is small, but well kept" });
clone_list=({1, 1, "lord", "/players/akira/mobs/lord", 0});
::reset(tick);
replace_program("room/room");
dest_dir=({"/players/akira/psi/hall7", "north" });
}
