inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);
short_desc=("Standing next to a mountain.");
long_desc=("A small mountain stands in front of you. It doesn't\n"+
           "look like it is very high, and the side looks like\n"+
           "it would be easy to go up.\n");
items=({"mountain", "Its not all that big, looks easy to climb.\n"});
dest_dir=({"players/akira/vag/juice1" ,"south",
           "players/akira/vag/m2", "up" });
property=({"vag_quest", "no_teleport"});
}
