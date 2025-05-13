inherit "/room/room";

void reset(int arg) {
   if (arg) return;
   clone_list=({
	1, 1, "squirrel","/players/bobo/monsters/squirrel", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="A wonderful forest filled with life.";
   long_desc=
	"You have entered a small, very vibrant forest.  Everywhere around "+
	"the forest is teeming with life.  To the north of here is a field "+
	"filled with some sort of grain crop.\n";
   dest_dir=({
	"/players/bobo/area/farm/f31","north",
	"/players/bobo/area/for/f4","east",
	"/players/bobo/area/for/f10","south",
	"/players/bobo/area/for/f2","west",
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
