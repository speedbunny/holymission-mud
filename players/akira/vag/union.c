inherit "room/room";
reset(tick){
    if(tick) return;
    set_light(1);
    short_desc=("Union battle-lines");
    long_desc=("This is were the union troops have dug-in to face the\n"+
      "confederate army. There are small logs stacked for cover\n"+
      "and the trench line goes on for a while. Shots fly by your\n"+
      "head as you stand here!\n");
    items=({"trench","This is were the troops take cover."});
    clone_list=({1,6,"union", "players/akira/mobs/union", 0});
    ::reset(tick);
    replace_program("room/room");
    dest_dir=({"players/akira/vag/bfield", "south",
      "players/akira/vag/union1", "west" });
property=({"vag_quest", "no_teleport"});
}
