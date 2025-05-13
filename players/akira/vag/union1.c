inherit "room/room";
reset(tick){
    if(tick) return;
    set_light(1);
    short_desc=("End of trench-line");
    long_desc=("This is the end of the trench-line. People here seem to\n"+
      "be a little more relaxed here. Very few shots are being fired\n"+
      "over here.\n");
    clone_list=({1,3,"union", "players/akira/mobs/union", 0});
    ::reset(tick);
    replace_program("room/room");
    dest_dir=({"players/akira/vag/bfield1", "south",
      "players/akira/vag/union", "east" });
property=({"vag_quest", "no_teleport"});
}
