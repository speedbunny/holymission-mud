inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);
short_desc=("On top of a mountain.");
long_desc=("This is the top of the mountain, from here you can\n"+
           "see for miles. The light from the rifts can be seem\n"+
           "for as far as you can see. The damage they must be\n"+
           "doing to this world is incedable.\n");
dest_dir=({"players/akira/vag/m6","north",
           "players/akira/vag/m2", "down",
           "players/akira/vag/m5", "east",
           "players/akira/vag/m4", "west" });
property=({"vag_quest", "no_teleport"});
}
