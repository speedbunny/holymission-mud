inherit "room/room";

int rope;

reset(arg) {
  object r;
  if(arg) return;
  set_light(1);
  short_desc="Rock ledge";
  long_desc="This is a narrow rock ledge by a blocked cave to the east. You would probably\n"
	+ "get a superb view down, but you are rather too vertigo-stricken to look at it.\n"
	+ "A large sturdy rock stands by your feet.\n";
  items=({ "rope", "@@rope_desc@@",
	"cave", "The cave is entrance is blocked",
	"entrance", "It looks rather dim and gloomy in there",
	"rock", "A large sturdy rock",
	"view", "No. You couldn't look at it. Too much vertigo" });
  r=clone_object("obj/rope");
  move_object(r,this_object());
  r->auto_tie("rock", this_object());
  rope=1;
}

init() {
  ::init();
  add_action("down", "down");
  add_action("up", "up");
  add_action("climb", "climb");
}

climb(str) { if(str=="up") return up(); if(str=="down") return down(); }

up() {
  if(!"players/moonchild/trollslayer/hillock"->query_rope()) return;
  return !this_player()->move_player("up#players/moonchild/trollslayer/rope");
}

down() {
  if(!rope) return write("You couldn't!\n");
  return !this_player()->move_player("down#players/moonchild/trollslayer/rope2");
}

tie(str) {
  if(str!="rock") return;
  rope=1;
  return 1;
}

untie() { rope=0; return 1; }

query_rope() { return rope; }

long(str) {
  if(!str) {
    ::long();
    if("players/moonchild/trollslayer/hillock"->query_rope())
	write("There is a rope hanging down from above.\n");
    return;
    }
  ::long(str);
}

rope_desc() {
  if(!"players/moonchild/trollslayer/hillock"->query_rope()) return;
  return "There is a rope hanging down from above. It looks like you could climb it";
}
