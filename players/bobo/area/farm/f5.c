inherit "/room/room";

void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="Roaming through the crops.";
   long_desc=
	"You are in the northern portion of the fields.  All around you "+
	"you can see crops except to the north where there is a thick "+
	"impenetrable mist that you dare not enter.  To the west you can "+
	"see a small clearing with a building in it.\n";
   dest_dir=({
	"/players/bobo/area/farm/f6","east",
	"/players/bobo/area/farm/f12","south",
	"/players/bobo/area/farm/f4","west",
   });
   items=({
	"crops","Some large grain type crop that is about seven feet high",
	"fields","These fields have to belong to someone as they are well kept",
	"building","It's not very large and you can't quite make out what it is",
	"mist","This mist is unlike any other mist that you have seen and is "+
	       "very scary",
   });
   replace_program("/room/room");
}
