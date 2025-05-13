inherit "/room/room";

void reset(int arg) {
   clone_list=({
	1, 1, "woman","/players/bobo/monsters/woman", 0,
   });
   if (arg) return;
   ::reset (arg);
   set_light(1);
   short_desc="Roaming through the crops.";
   long_desc=
	"You are on the southeastern edge of the fields.  The crops here "+
	"are in a sorry state.  It looks as though they've been thrashed "+
	"and trampled by something or another.  To the south there is a "+
	"forest and to the east there is the side of a building.\n";
   dest_dir=({
	"/players/bobo/area/farm/f28","north",
	"/players/bobo/area/for/f7","south",
	"/players/bobo/area/farm/f34","west",
   });
   items=({
	"crops","Some large grain type crop that is about seven feet high",
	"fields","These fields have to belong to someone as they are well kept",
	"mist","This mist is unlike any other mist that you have seen and is "+
	       "very scary",
	"forest","A quiet, serene looking forest, the trees are very large",
   });
   replace_program("/room/room");
}
