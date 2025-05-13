inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="A wonderful forest filled with life.";
long_desc=
"You have entered a very large, very vibrant forest.  Everywhere\n"+
"around you there is life.  Light shines down from through the canopy of\n"+
"spruce, pine and birch trees.  This looks like a good spot to camp.\n";
dest_dir=({
	"players/bobo/rooms/forrest/14.c","east",
	"players/bobo/rooms/forrest/12.c","west",
	"players/bobo/rooms/forrest/24.c","north",
	"players/bobo/rooms/forrest/2.c","south",
});
items=({
	"canopy","Not to dense, this lets a lot of light shine down on you",
	"trees","There are many different sizes of trees in this area",
});
}
init() {
  ::init ();
add_action("enter","enter");
}
enter(str) {
if(str=="tree") {
write("You enter a large pine tree.\n");
this_player()->move_player("enters the tree#players/bobo/rooms/forrest/tree");
return 1;
}
}
