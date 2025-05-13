inherit "room/room";
 
object obj;
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="In the Quiet River";
    long_desc="You're swimming in the Quiet River.\n"+
     "At both sides of the river there are steep rocks.\n";
 
}
init() {
::init();
  add_action("dir_north","north");
  add_action("dir_south","south");
  add_action("swim","swim");
}
 
 
dir_south() {
 write("You're swimming dowm the river.\n");
 this_player()->move_player("south#players/kelly/rooms/wastelands/river1");
 return 1;
}
dir_north() {
 write("You're swimming up the river.\n");
 this_player()->move_player("north#players/kelly/rooms/wastelands/river3");
 return 1;
}
 
swim(str) {
  if(!str) { write("Which direction?\n"); return 1; }
   else {
    if (str=="n" || str=="north") dir_north();
    if (str=="s" || str=="south") dir_south();
    return 1;
  }
}
