inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Lakeside";
  long_desc="At the bottom of the huge cliff-face, you find the view transformed, to one\n"
	+ "of a placid lake-side. The cliffs still block any egress to the east, south or\n"
	+ "west, but a rope bridge leads north onto an island which stands in the centre\n"
	+ "of the lake.\n";
  dest_dir=({ "players/airborne/temple/entrance/bridge1", "north" });
  items=({ "rope", "@@rope_desc@@",
	"cliff-face", "A huge sheer cliff-face",
	"cliff", "A huge sheer cliff-face",
	"bridge", "An old but sturdy rope bridge",
	"rope bridge", "An old but sturdy rope bridge" });
}

init() {
  ::init();
  add_action("up", "up");
  add_action("climb", "climb");
}

climb(str) { if(str=="up" || str=="rope") return up(); }

up() {
  if(!"players/moonchild/trollslayer/ledge"->query_rope()) return;
  return !this_player()->move_player("up#players/moonchild/trollslayer/rope2");
}

long(str) {
  if(!str) {
    ::long();
    if("players/moonchild/trollslayer/ledge"->query_rope())
	write("There is a rope hanging down from above.\n");
    return;
    }
  ::long(str);
}

rope_desc() {
  if(!"players/moonchild/trollslayer/hillock"->query_rope()) return;
  return "There is a rope hanging down from above. It looks like you could climb it";
}
