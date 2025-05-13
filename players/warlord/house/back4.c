inherit"room/room";
reset(arg) {
::reset(arg);
if(arg) return;
set_light(1);
short_desc="Back yard.\n";
long_desc=
"You are in the backyard of the house. You can see a large tree here.\n"+
"From the tree a large branch protrudes. Off of the branch is a swing.\n";
items=({
"swing","This is a rope swing with a wooden seat. Swing on it",
"tree","A very large tree",
});
dest_dir=({
"players/warlord/house/back3","south",
"players/warlord/house/back5","east",
});
}
init() {
::init();
add_action("swing","swing");
}
swing() {
write("You get onto the swing and start swinging. You feel like a kid again.\n");
say(this_player()->query_name()+" starts to swing on the swing.\n");
return 1;
}
