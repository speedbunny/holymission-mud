inherit "room/room";
#define PATH "players/baalthasar/area/keep"

reset(arg) {
if (arg) return;

set_light(1);
short_desc = "Mountain road";
long_desc =
"       The pebble strewn path continues on through the \n"
+"mountains here.  Cliff walls force the path to continue \n"
+"north only.  Far to the north you see a very bright light. \n\n";

dest_dir =
({
PATH + "/mroad1", "north",
PATH + "/mroad3", "south"
});
items = ({ "pebbles", "Rocks litter this tight pass",
"walls", "These sheer stone walls look impassible",
"cliff", "These sheer stone walls look impassible",
"light", "It appears to be the sun reflecting off some surface.."
});
}
