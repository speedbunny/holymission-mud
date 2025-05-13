inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);
short_desc=("In a open field");
long_desc=("This is a small open field that the farmers of the town\n"+
           "use for there cows and sheep. The grass in the field looks\n"+
           "like it has been burnt. Most of the trees that stand at the\n"+
           "edge of the field are destroied.\n");
items=({"grass", "It is all burnt",
        "trees", "They look to have been destroied.\n" });
clone_list=({1,1,"juicer","players/akira/mobs/juicer", 0});
::reset(tick);
dest_dir=({"players/akira/vag/m1","north",
           "players/akira/vag/field4", "west",
           "players/akira/vag/rift3", "east" });
property=({"vag_quest", "no_teleport"});
}
