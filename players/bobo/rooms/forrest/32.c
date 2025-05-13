inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="Lumber Mill.";
long_desc=
"You have come upon a small encampment.  There are a few buildings in the\n"+
"center of this area.  Other that that there is not much to see here\n"+
"except maybe the complete lack of trees in this area.\n";
dest_dir=({
	"players/bobo/rooms/forrest/33.c","east",
	"players/bobo/rooms/forrest/31.c","west",
	"players/bobo/rooms/forrest/21.c","south",
	"players/bobo/rooms/forrest/43.c","north",
});
items=({
	"encampment","A few small building in the center of the field",
   "trees","Except for the fact that there are none here everything is normal",
});
}
init() {
  ::init();
  add_action("enter","enter");
}
enter(str) {
  if (str=="encampment") {
  write("You enter the encampment.\n");
  this_player()->move_player("Enters the encampment#players/bobo/rooms/forrest/camp");
return 1;
}
}
