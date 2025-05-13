inherit "room/room";
reset(tick){
    if(tick) return;
    set_light(1);
    short_desc=("End of Confederate Battle-line.");
    long_desc=("This is the far end of the Confederate battle-line.\n"+
      "The troops here look to be getting ready too try and\n"+
      "flank the union lines.\n");
    clone_list=({1,4,"reb", "players/akira/mobs/reb", 0});
    ::reset(tick);
    replace_program("room/room");
    dest_dir=({"players/akira/vag/bfield1", "north",
      "players/akira/vag/reb", "east" });
property=({"vag_quest", "no_teleport"});
}
