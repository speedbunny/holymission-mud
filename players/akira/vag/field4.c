inherit "room/room";
reset(arg){
    ::reset(arg);
    set_light(1);
    short_desc=("In a small field");
    long_desc=("There is something about this field that just doesn't\n"+
      "feel right. The time and space here seem to be off. In\n"+
      "the distance you can here loud bangging noises coming\n"+
      "from the west.\n");
    dest_dir=({"players/akira/vag/juice1", "east",
      "players/akira/vag/bfield", "west"});
property=({"vag_quest", "no_teleport"});
}
