inherit "room/room";

status trap_set;

reset(arg) {
  if(arg) return;
  short_desc="A patch of bare ground";
  long_desc="You are standing on a patch of bare ground.\n"
	+ "There looks to be a hole in the ground here.\n";
  dest_dir=({ "players/moonchild/gnome/dpath", "southwest",
	"players/moonchild/gnome/inpit", "down" });
  items=({ "hole", "Looks like a pit, probably dug as a trap" });
  property=({ "no_teleport" });
}

init() {
  ::init();
  if(trap_set) {
    write("You fall down a pit!\n");
    transfer(this_player(),"players/moonchild/gnome/inpit");
    trap_set=0;
  }
}

set_trap() { trap_set=1; }
