/* there is not mean to be any trace of a secret entrance oncve you leave
   because it is a secret.  i want other players to figure it out for
   themselves. */
inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="The shed.";
long_desc=
"The shed seems smaller on the inside than you thought it was on the\n"+
"outside.  There are various tools spread about but mostly they lay\n"+
"in a heap in the corner.  There are bags of dirt and other materials\n"+
"to take care of the grounds here as well.\n";
dest_dir=({
	"players/bobo/rooms/island/shed.c","out",
});
items=({
	"tools","A large pile of tools sits in the corner of the shed",
	"bags","Bags of soil lie on the floor here",
	"heap","A large pile of tools was thron here hap hazardly",
});
}
init () {
::init();
add_action("open","open");
add_action("search","search");
}
open(str) {
if(str=="trap door") {
write("you open the trap door and go down.\n");
this_player()->move_player("goes down a trapdoor#players/bobo/rooms/island/desk");
return 1;
}
}
search(arg) {
if(arg !="tools") return 0;
write("You found a trap door.\n");
return 1;
}
