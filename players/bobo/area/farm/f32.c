inherit "/room/room";

void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="Roaming through the crops.";
   long_desc=
	"You are on the souther edge of the fields.  The crops are almost "+
	"as abundant here as they are everywhere else.  It appears that "+
	"there have been animals eating them.  To the south is a quiet, "+
	"peaceful looking forest.\n";
   dest_dir=({
	"/players/bobo/area/farm/f25","north",
	"/players/bobo/area/farm/f33","east",
	"/players/bobo/area/for/f4","south",
	"/players/bobo/area/farm/f31","west",
   });
   items=({
	"crops","Some large grain type crop that is about seven feet high",
	"fields","These fields have to belong to someone as they are well kept",
	"forest","A quiet, serene looking forest, the trees are very large",
   });
   replace_program("/room/room");
}
