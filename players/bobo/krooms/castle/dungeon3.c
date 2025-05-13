inherit "room/room";
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="In a dungeon";
    long_desc="You in the dungeon of the castle.\n"+
      "To the north there's a thick iron cell-door.\n";
    dest_dir=({
	"players/bobo/krooms/castle/dungeon2","east",
	"players/bobo/krooms/castle/dungeon4","west",
   });
    items=({
    "door","No chance to move it",
    });
}
 
init() {
::init();
  add_action("north","north");
  add_action("open","open");
}
 
north() {
  if(!"players/bobo/krooms/castle/dungeon1"->query_lever_up())
	this_player()->move_player("north#players/bobo/krooms/castle/cell2");
  else {
    write("The cell-door is locked!\n");
    say(this_player()->query_name()+" tries to go north, but runs "+
       "straight into the door.\n");
    }
  return 1;
}

open(str) {
  if(str!="door") return;
  write("This door can't be opened from here.\n");
  say(this_player()->query_name()+" tries to open the door.\n");
  return 1;
}



