inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("A dead end.\n");
long_desc=("The hallway comes to a dead end here. There is a small\n"+
           "flight of stairs that seems to lead down in the center\n"+
           "of the room. The walls seem to have some strange writing\n"+
           "on them.\n");
items=({"stairs", "They seem to lead down.",
        "walls", "They have some strange writing on them.",
        "writing", "You can not make out what it says" });
dest_dir=({"/players/akira/area/hall3", "west",
           "/players/akira/area/well", "down" });
property=({"no_teleport"});
}
