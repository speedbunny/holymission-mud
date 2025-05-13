inherit "room/room";
 
object obj;
 
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="In the magic swamps";
    long_desc="You're in magic swamps.\n"+
     "It seems that you can go everywhere and nowhere.\n";
    dest_dir=({
    "players/kelly/rooms/swamps/swamp1","south",
    "players/kelly/rooms/swamps/swamp8","west",
    "players/kelly/rooms/swamps/swamp10","north",
    "players/kelly/rooms/swamps/swamp5","east",
   });
   call_out("sink",30);
}
 
init() {
::init();
  add_action("shouting","shout");
  add_action("shouting","tell");
}
 
sink() {
  if(environment(this_player())!=this_object()) return;
  write("The ground gets softer and you seem to drown in the mud.\n");
  this_player()->move_player("into nowhere#players/kelly/rooms/swamps/under_sw6");
  return 1;
}
 
shouting() {
  write("You try to shout, but it seems the swamps swallow all your ");
  write("words.\n");
  return 1;
}
