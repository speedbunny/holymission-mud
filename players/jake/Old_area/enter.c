inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "enter";
  long_desc = 
        "You are standing in a rather large entrance room.\n"
	"The entrance is to a large building.  You hear all sorts of\n"
	"strange noises from within.\n"
"The building is now closed due to conflicts with Holy Mission themes.\n";
  dest_dir = ({ "players/jake/path5.c","south",
});
  clone_list = ({ 1, 1, "bill", "players/jake/monster/bill", 0 });

::reset();
replace_program("room/room");
}
