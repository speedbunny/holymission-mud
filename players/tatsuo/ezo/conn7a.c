#define PPATH "/players/tatsuo/ezo/"
inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(0);
   short_desc = "Inside a tree";
   long_desc = 
        "You are inside a hollow tree. This must be a very big tree, so you\n"+
        "can easily move in here. There is some kind of ladder attached to\n"+
        "the wall, leading up.\n";

   dest_dir=({
	"/players/tatsuo/ezo/forest/t20","up",
	PPATH + "conn6a","down",
   });
   replace_program("room/room");
}
