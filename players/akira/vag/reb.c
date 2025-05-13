inherit "room/room";
reset(tick){
    if(tick) return;
    set_light(1);
    short_desc=("Confederate battle-line");
    long_desc=("This is the confederate battle-line. Theyare standing out\n"+
      "in the open and shotting at the union troops. The ground\n"+
      "is wet with the blood of the fallen. You do not think it\n"+
      "would be a good idea to just stand around here.\n");
    clone_list=({1, 6, "reb" ,"players/akira/mobs/reb", 0});
    ::reset(tick);
    replace_program("room/room");
    dest_dir=({"players/akira/vag/bfield", "north",
      "players/akira/vag/reb1", "west" });
property=({"vag_quest", "no_teleport"});
}
