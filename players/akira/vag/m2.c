inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);
short_desc=("A small ledge");
long_desc=("This is a small ledge in the side of the mountain.\n"+
           "From here you can look down on the rifts that are\n"+
           "ripping this world apart. You can see the top of the\n"+
           "mountain from here.\n");
dest_dir=({"players/akira/vag/m3", "up",
           "players/akira/vag/m1", "down" });
property=({"vag_quest", "no_teleport"});
}
