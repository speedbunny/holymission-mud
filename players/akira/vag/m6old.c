inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);
short_desc=("A small throne room");
long_desc=("This is a small throne room carved from the side of\n"+
           "the mountain. From here the Evil Timelord Thanos can watch\n"+
           "as the world below is destroied, then move in and take\n"+
           "over what is left.\n");
move_object(clone_object("players/akira/mobs/thanos"), this_object());
::reset(tick);
dest_dir=({"players/akira/vag/m3", "south" });
property=({"no_teleport"});
}
