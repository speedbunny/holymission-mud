inherit "room/room";
 
object obj;
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="In the ocean";
    long_desc="You're swimming in the sea.\n"+
     "To the west lies the shore.\n";
 
}
init() {
::init();
  add_action("dir_west","west");
  add_action("dir_other","south");
  add_action("dir_other","east");
}
 
 
dir_west() {
 write("You leave the water.\n");
 this_player()->move_player("west#players/kelly/rooms/wastelands/seashore");
 return 1;
}
dir_other() {
 write("You don't dare to swim further!\n");
 return 1;
}
 
