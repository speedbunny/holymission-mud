inherit "/room/room";
 
void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="A road to Mythwood";
long_desc=
	"You are traveling on a road leading to Mythwookd.  The road becomes "+
	"a path to the north and returns to the town to the south.\n";
   dest_dir=({
	"/players/bobo/krooms/mythwood/mythpath8","north",
	"/players/bobo/krooms/vill/road8","south",
   });
   replace_program("room/room");
}
