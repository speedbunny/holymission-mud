inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("A small room");
long_desc=("This is a small room given to students who live in the\n"+
           "tower while they study. There is not must to the room.\n"+
           "Other than a bed and a desk, nothing much is in here.\n");
items=({"bed", "This is a rather dirty looking bed",
        "desk", "This is were the students can do homework" });
dest_dir=({"/players/akira/psi/hall6", "east" });
}
