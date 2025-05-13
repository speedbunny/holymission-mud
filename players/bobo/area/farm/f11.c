inherit "/room/room";

void reset(int arg) {
   if (arg) return;
   clone_list=({
	1, 1, "crow","/players/bobo/monsters/crow", 0,
   });
   ::reset(arg);
   set_light(1);
   short_desc="Roaming through the crops.";
   long_desc=
	"You are somewhere in the middle of the fields.  This area looks "+
	"exactly like the rest of the fields.  There is nothing different "+
	"here, except maybe that you are here now instead of there.  Or "+
	"have you really gone anywhere?\n";
   dest_dir=({
	"/players/bobo/area/farm/f11","north",
	"/players/bobo/area/farm/f12","east",
	"/players/bobo/area/farm/f18","south",
	"/players/bobo/area/farm/f10","west",
   });
   items=({
	"crops","Some large grain type crop that is about seven feet high",
	"fields","These fields have to belong to someone as they are well "+
		 "kept",
   });
   replace_program("/room/room");
}
