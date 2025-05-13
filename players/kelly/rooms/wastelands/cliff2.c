inherit "room/room";
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A cliff path";
    long_desc="You're on a cliff path.\n"+
      "You can climb down to the shore of the ocean.\n"+
      "The path continues to the east.\n";
    dest_dir=({
      "players/kelly/rooms/wastelands/cliff1","east",
      "players/kelly/rooms/wastelands/seashore","down",
    });
    items=({
      "path","A path leading to the wastelands"
    });
}
 
init() {
 ::init();
  add_action("jump","jump");
}
 
jump(str) {
  if(str!="down" && str!="down cliff") return ;
    write("You jump down the cliff.\n");
    say(call_other(this_player(),"query_name")+" jumps heroically "+
      "down the cliff.\n");
    write("You're falling into the sea.\n");
    this_player()->move_player("#players/kelly/rooms/wastelands/sea2");
    return 1;
}
 
