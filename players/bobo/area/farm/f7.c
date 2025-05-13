inherit "/room/room";

void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="Roaming through the crops.";
   long_desc=
	"You are in the northeast corner of the fields.  Crops are being "+
	"cultivated in a grid pattern all around you.  To the north there "+
	"is a thick, impenetrable mist that chills you to the bone by the "+
	"site of it.  To the east you can see a some buildings.\n";
   dest_dir=({
	"/players/bobo/area/farm/f14","south",
	"/players/bobo/area/farm/f6","west",
   });
   items=({
	"crops","Some large grain type crop that is about seven feet high",
	"fields","These fields have to belong to someone as they are well kept",
	"mist","This mist is unlike any other mist that you have seen and is "+
	       "very scary",
	"buildings","A building is blocking your way directly east byt there "+
		    "appears to be a town",
   });
   replace_program("/room/room");
}
