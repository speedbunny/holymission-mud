inherit "room/room";
reset(tick){
    if(tick) return;
    set_light(1);
    short_desc=("At the edge of a city");
    long_desc=("You are standing at the edge of a city. You have never\n"+
      "seen buildings this size. They seem to reach to the heavens.\n"+
      "From the city you can here loud screems and bangging sounds.\n"+
      "There is also a great deal of smoke coming from most of the\n"+
      "buildings in the city.\n");
    items=({"buildings", "They look to have been attacked" });
    dest_dir=({"players/akira/vag/city2", "east",
      "players/akira/vag/juice", "west" });
property=({"vag_quest", "no_teleport"});
}
