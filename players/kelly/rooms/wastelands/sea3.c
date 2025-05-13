inherit "room/room";
 
object obj;
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="In the ocean";
    long_desc="You're swimming in the sea.\n"+
     "To the north lies the shore.\n";
 
}
init() {
::init();
  add_action("dir_north","north");
  add_action("dir_other","south");
  add_action("dir_other","west");
  add_action("dir_east","east");
}
 
 
dir_north() {
 write("You leave the water.\n");
 this_player()->move_player("north#players/kelly/rooms/wastelands/mouth");
 return 1;
}
dir_other() {
 write("You don't dare to swim further!\n");
 return 1;
}
dir_east() {
 write("You're swimming eastwards.\n");
 this_player()->move_player("east#players/kelly/rooms/wastelands/sea2");
 return 1;
}
 
