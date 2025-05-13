inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);
short_desc=("In front of a large rift.");
long_desc=("A large rift in time and space stands before you. The\n"+
           "light from it fills this part of the town. All the buildings\n"+
           "around the rift are destroyed. Judging from the foot prints\n"+
           "in front of the rift, a lot of people came through at this\n"+
           "point.\n");
items=({"rift", "A rift in time and space, opened by a Timelord!\n",
        "buildings","They are all destroied!\n",
        "prints", "They look like human tracks.\n" });
clone_list=({ 1, 4, "indian","players/akira/mobs/indian", 0});
::reset(tick);
dest_dir=({"players/akira/vag/town", "west" });
property=({"vag_quest", "no_teleport"});
}
