inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "spiderroom";
  long_desc = 
        "You have entered a room full of cobwebs.\n"
        "You see many cocoons the size of small pigs in here.\n";
  items = ({ "cocoon", "This is a large cocoon the size of a small pig",
	"cobweb", "Larger than normal cobwebs" });
  dest_dir = ({ "players/jake/basej.c", "west" });
  clone_list = ({ 1, 2, "spider", "players/jake/monster/spider", 0 });

::reset();
replace_program("room/room");
}


