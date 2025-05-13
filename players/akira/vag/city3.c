inherit "room/room";
reset(tick){
    if(tick) return;
    set_light(1);
    short_desc=("In a city.");
    long_desc=("The city streets look to be very damaged. You have no\n"+
      "clue as to what could have made holes like this in the\n"+
      "street. Too the north you can se a large building.\n");
    items=({"hole","They are huge holes in the street.\n"});
    dest_dir=({"players/akira/vag/city4", "north",
      "players/akira/vag/city2", "south" });
property=({"vag_quest", "no_teleport"});
}
