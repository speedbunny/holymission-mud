inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);
short_desc=("An open field");
long_desc=("This is an open field were cows come to feed. The grass\n"+
           "is very green, and it looks like a good place to let animals\n"+
           "graze. Most of the trees around the field looks as if they\n"+
           "have been blown-up.\n");
items=({"grass", "It is very green.\n",
        "trees", "They have been blown-up!\n"});
clone_list=({ 1,2,"juicer","players/akira/mobs/juicer",0 });
::reset(tick);
dest_dir=({"players/akira/vag/edge", "east",
           "players/akira/vag/rift3", "west" });
property=({"vag_quest", "no_teleport"});
}
