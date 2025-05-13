inherit "room/room";
 
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A cliff path";
    long_desc="You're on a cliff path.\n"+
     "To the north the Wastelands begin.\n"+
      "The path continues to the west.\n";
    dest_dir=({
    "players/kelly/rooms/wastelands/waste8","north",
    "players/kelly/rooms/wastelands/cliff2","west",
   });
}
 
init() {
  ::init();
  add_action("jump","jump");
}
 
jump(str) {
  if(str!="down" && str!="down cliff") return;
    write("You jump down the cliff.\n");
    say(call_other(this_player(),"query_name")+" jumps heroically "+
     "down the cliffs.\n");
    write("You're falling into the sea.\n");
    this_player()->move_player("#players/kelly/rooms/wastelands/sea1");
    return 1;
}
 
