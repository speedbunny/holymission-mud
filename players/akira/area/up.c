inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("At a dead end.\n");
long_desc=("The hall seems to come to a stop here. The only thing in the\n"+
           "hall at this point is a small flight of stairs that seems to\n"+
           "lead to a second floor. The walls here are covered in some\n"+
           "strange writing.\n");
items=({"hall", "This is a dead end hallway",
        "walls", "They seem to be covered with some strange writing.",
        "writing", "You can not make out what it says",
        "stairs", "They seem to lead up to a second floor" });
dest_dir=({"/players/akira/area/hall2", "east",
           "/players/akira/area/rec", "up" });
property=({"no_teleport"});
}
