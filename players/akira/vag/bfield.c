inherit "room/room";
reset(arg){
    ::reset(arg);
    set_light(1);
    short_desc=("A battlefield");
    long_desc=("This looks to be some kind of battlefield. Too the north\n"+
      "you can see troops dug-in on the ridge. Above there line\n"+
      "is a blue and red flag with white stars. Just south of you\n"+
      "is a line of troops dressed in gray. There flag is red with\n"+
      "white stars. Shots fly by your head as you stand here!\n");
    items=({"troops", "You have never seen a soldier that looks like this.\n",
      "lines", "They are set up to have a war!\n" });
    dest_dir=({"players/akira/vag/union", "north",
      "players/akira/vag/reb", "south",
      "players/akira/vag/field4", "east",
      "players/akira/vag/bfield1", "west" });
property=({"vag_quest", "no_teleport"});
}
