inherit "/room/room";

void reset(int arg) {
   if (arg) return;
   clone_list=({
	1, 1, "rabbit","/players/bobo/monsters/rabbit", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="Roaming through the crops";
   long_desc=
	"You are on the westen edge of the fields.  All around you there "+
	"are crops being grown in a grid pattern.  They seem to go on in "+
	"all directions as far as you can see except to the west where "+
	"there is a thick mist unlike any that you have ever seen, the "+
	"mere sight of it makes you tremble.\n";
   dest_dir=({
	"/players/bobo/area/farm/f8","north",
	"players/bobo/area/farm/f16","east",
	"/players/bobo/area/farm/f22","south",
   });
   items=({
	"crops","Some lare grain type crop that is about seven feet high",
	"fields","These fields have to belong to someone as they are well"+
		 " kept",
	"mist","This mist is unlike any other mist that you have seen and "+
		"is scary",
   });
   replace_program("room/room");
}
