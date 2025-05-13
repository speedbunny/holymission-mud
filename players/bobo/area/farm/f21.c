inherit "/room/room";

void reset(int arg) {
   ::reset(arg);
   if (arg) return;
   set_light(1);
   short_desc="Roaming through the crops.";
   long_desc=
	"You are on the western edge of the fields.  The crops here are "+
	"as well maintained as they are in the rest of the field.  To the "+
	"east you can see the side of a building.  Other than that nothing "+
	"distinguishes this place from any other.\n";
dest_dir=({
	"/players/bobo/area/farm/f14","north",
	"/players/bobo/area/farm/f28","south",
	"/players/bobo/area/farm/f20","west",
   });
   items=({
	"crops","Some large grain type crop that is about seven feet high",
	"fields","These fields have to belong to someone as they are well kept",
	"building","A building is blocking your way directly east but there "+
		   "appears to be a town",
   });
   replace_program("room/room");
}
