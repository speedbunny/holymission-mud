inherit "room/room";
reset (arg) {
if (arg) return;
set_light(-10);
short_desc="Inside of a tree.";
long_desc="You have entered an extremely large tree somehow.\n";
dest_dir=({
	"players/bobo/rooms/forrest/13.c","out"
});
items=({
	"bark","Somehow this tree has been hollowed out.  The bark is dry."
});
}
