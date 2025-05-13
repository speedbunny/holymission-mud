inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="The house.";
long_desc=
"As you near the house you stop and stare for a moment, awe struck\n"+
"by it's magnifigance.  It seems rather large for what you think is\n"+
"the normal oriental house.  It has two stories and is surrounded \n"+
"by flowers.\n";
dest_dir=({
	"players/bobo/rooms/island/ring.c","north",
	"players/bobo/rooms/island/yard1.c","south",
});
items=({
	"house","A beatiful house created out of oriental architecture",
	"flowers","Many beautiful flowers line the boxes near the house",
});
}
init () {
::init();
add_action("enter","enter");
}
enter(str) {
if(str=="house") {
write("You enter the house.\n");
this_player()->move_player("Goes inside#players/bobo/rooms/island/house1");
return 1;
}
}
