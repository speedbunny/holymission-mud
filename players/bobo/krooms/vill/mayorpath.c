inherit "/room/room";

void reset (int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="Mayor's property";
   long_desc=
	"You are on the side of the mayor's house.  This area has "+
	"many overgrown shrubs and hedges here.  It is difficult to "+
	"follow the path which seems to end abruptly in front of a "+
	"thick hedge.\n";
   dest_dir=({
	"/players/bobo/krooms/vill/mayorsgarden","northwest",
   });
   items=({
	"path","It seems that the path hasn't been used for a long time",
	"shrubs","Overgrown and wild, these shrubs are all over the place",
	"house","This is the mayor's house.  It is very big and splendid",
	"hedge","A hedge of hazelnut perennial",
   });
replace_program("room/room");
}
