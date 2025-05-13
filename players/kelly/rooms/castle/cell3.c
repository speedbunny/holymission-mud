inherit "room/room";
 
 
reset(arg) {
    if (arg) return;
    set_light(0);
    no_castle_flag=1;
    short_desc="In a cell";
    long_desc="You're in a cell. There's no opening here except the door to the south.\n";
    items=({
    "door","No chance to move it",
    });
}
 
init() {
::init();
  add_action("south","south");
}
 
south() {
  if(!"players/kelly/rooms/castle/dungeon1"->query_lever_up())
    this_player()->move_player("north#players/kelly/rooms/castle/dungeon4");
  else {
    write("The cell-door is locked!\n");
    say(this_player()->query_name()+" tries to go south, but runs "+
       "straight into the door.\n");
    }
  return 1;
}
 
