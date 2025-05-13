inherit "room/room";
 
object obj;
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="The seashore";
    long_desc="You are at the shore of the ocean.\n" +
     "Here the Quiet River leads into the sea.\n"+
     "To west you're able to swim in the Quiet River and to the \n"+
     "south is the wide ocean!\n";
 
     dest_dir=({
       "players/kelly/rooms/wastelands/seashore","east",
     });
     items=({
       "ocean","The wide ocean, far in the distance you think youc an see a island",
       "river","It's called Quite River",
     });
}
 
init() {
::init();
  add_action("dir_west","west");
  add_action("dir_south","south");
}
 
dir_west() {
    write("You jump into the water of the Quiet River.\n");
    this_player()->move_player("west#players/kelly/rooms/wastelands/river1");
    return 1;
 
}
dir_south() {
    write("You jump into the ocean.\n");
    this_player()->move_player("south#players/kelly/rooms/wastelands/sea3");
    return 1;
 
}
 
