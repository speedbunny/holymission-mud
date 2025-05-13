inherit "/room/room";

void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="A road outside of a village.";
long_desc=
	"You are on a road leading which winds its way through a strange "+
	"forest.  Though you can see a red rock to the south there isn't "+
	"anything else out of the ordinary that you can tell but still...\n";
   dest_dir=({
	"/players/bobo/krooms/vill/woodroad","north",
	"/players/bobo/krooms/vill/road5","south",
   });
   items=({
	"forest","A strange feeling comes over you as you look at the forest",
	"rock","A big red rock shows itself in the distant south",
   });
    replace_program("room/room");
}
