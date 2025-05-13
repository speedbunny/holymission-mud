inherit "room/room";
reset(tick){
    if(tick) return;
    set_light(1);
    short_desc=("In a bunker.");
    long_desc=("This is a heavy bunker used for holding important people.\n"+
      "The walls are very thick, you think it would take a lot\n"+
      "to even put a dent in them. This place looks well lived, all\n"+
      "the furniture in here looks like it is worth a lot. There is\n"+
      "a large map on the wall.\n");
    clone_list=({1,1,"hitler", "players/akira/mobs/hitler", 0});
    ::reset(tick);
    replace_program("room/room");
    items=({"furniture", "It is all very nice looking.",
      "map", "It is of a land that you have never seen before."});
    dest_dir=({"players/akira/vag/in", "south" });
property=({"vag_quest", "no_telport"});
}
