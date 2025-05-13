inherit "room/room";
reset(tick){
    if(tick) return;
    set_light(1);
    short_desc=("Dead End.");
    long_desc=("This part of the street looks to have been blocked off.\n"+
      "There are huge pillars blocking the road so nothing can\n"+
      "get by. This part of the street seem to be empty, there\n"+
      "is not a soul in sight.\n");
    clone_list=({1,1,"ss", "players/akira/mobs/ss", 0});
    ::reset(tick);
    replace_program("room/room");
    items=({"pillars", "They block the road."});
    dest_dir=({"players/akira/vag/city2", "north" });
property=({"vag_quest", "no_teleport"});
}
