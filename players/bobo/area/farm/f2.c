inherit "room/room";

void reset(int arg) {
   if (arg) return;
   clone_list=({
	1, 1, "rabbit","players/bobo/monsters/rabbit", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="Roaming through the crops.";
   long_desc=
	"You are in the northern portion of the fields.  All around you "+
	"you can see crops except to the north where there is a thick"+
	"impenetrable mist that you dare not enter.\n";
   dest_dir=({
	"/players/bobo/area/farm/f3","east",
	"/players/bobo/area/farm/f9","south",
	"players/bobo/area/farm/f1","west",
   });
   items=({
	"crops","Some large grain type crop that is about seven feet high",
	"fields","These fields have to belong to someone as they are well kept",
	"mist","This mist is unlike any other mist that you have seen and is "+
	       "very scary",
   });
   replace_program("room/room");
}
