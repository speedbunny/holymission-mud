inherit "room/room";

void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="Roaming through the crops.";
   long_desc=
	"You are in the northwest corner of the fields.  Crops are being "+
	"cultivated in a grid pattern all around you.  Both to the north "+
	"and the west there is a thick, impenetrable mist that you dare "+
	"not go near.\n";
   dest_dir=({
	"/players/bobo/area/farm/f2","east",
	"/players/bobo/area/farm/f8","south",
   });
   items=({
	"crops","Some large grain type crop that is about seven feet high",
	"fields","These fields have to belong to someone as they are well kept",
	"mist","This mist is unlike any othere mist that you have seen and is scary",
   });
   replace_program("room/room");
}
