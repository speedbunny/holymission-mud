inherit "room/room";
reset(tick){
    if(tick) return;
    set_light(1);
    short_desc=("In a city.");
    long_desc=("From here you can see that the city has taken a great\n"+
      "deal of damage. Most of the buildings are on fire or\n"+
      "half destroied. There is a main street that leads to the\n"+
      "north and south.\n");
    items=({"buildings", "They are really in bad shape.\n"});
    dest_dir=({"players/akira/vag/city3" ,"north",
      "players/akira/vag/city1", "south",
      "players/akira/vag/edge", "west" });
property=({"vag_quest", "no_teleport"});
}
