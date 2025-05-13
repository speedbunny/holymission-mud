inherit "/room/room";

void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="A wonderful forest filled with life.";
   long_desc=
	"You are in the middle of a small, very vibrant forest.  Everywhere "+
	"around you the forest is teeming with life.  There are many "+
	"different types of trees here and there is light streaming down "+
	"from the canopy.  A thick underbrush has grown to the west blocking "+
	"your way.\n";
   dest_dir=({
	"/players/bobo/area/for/f1","north",
	"/players/bobo/area/for/f9","east",
	"/players/bobo/area/for/f15","south",
   });
   items=({
	"forest","A wonderfully light and vibrant forest",
	"life","The trees are especially healthy and there are animals here "+
	       "and there",
	"field","A large grain field that seems to go on forever",
	"grain","Some sort of grain, but you aaren't quite familiar with it",
	"crop","Some sort of grain.  Though you're not sure which",
	"underbrush","The underbrush here is too thick to pass",
   });
   replace_program("/room/room");
}
