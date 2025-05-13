inherit "/room/room";

void reset(int arg) {
   ::reset(arg);
   if (arg) return;
   set_light(1);
   short_desc="Roaming through the crops.";
   long_desc=
	"You are on the southwestern edge of the fields.  The crops are "+
	"as abundant here as everywhere else.  To the west there is a "+
	"thick impenenetrable mist that frightens you to go near.  To the "+
	"south there is a quiet, peaceful lookig forest.\n";
   dest_dir=({
	"/players/bobo/area/farm/f22","north",
	"/players/bobo/area/farm/f30","east",
	"/players/bobo/area/for/f1","south",
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
