inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="The shed.";
long_desc=
"In the center of this area is what looks like a large storage shed.\n"+
"It is very neat and well kept.  Around it on the ground are wood chips\n"+
"giving this area a subtle beauty.\n";
dest_dir=({
	"players/bobo/rooms/island/yard8.c","east",
	"players/bobo/rooms/island/yard9.c","west",
	"players/bobo/rooms/island/yard11.c","north",
	"players/bobo/rooms/island/ring.c","south",
});
items=({
	"shed","A large storage shed made of wood",
	"wood chips","Covering the ground these give the area a nice smell",
});
smell="Smells like woodchips.\n";
}
init () {
::init();
add_action("enter","enter");
}
enter(str) {
if(str=="shed") {
write("You enter the shed.\n");
this_player()->move_player("Goes into the shed#players/bobo/rooms/island/shed1");
return 1;
}
}
