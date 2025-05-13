#define PPATH "/players/tatsuo/ezo/"
inherit "room/room";
   reset(arg) {
   if(arg) return;
   set_light(0);
   short_desc = "A narrow tunnel";
   long_desc = 
	"GASTP! This tunnel is narrow. You hope that you won't get stuck\n"+
	"here! With the roughly hewn walls, that have sharp stones tearing\n"+
	"at your clothing, you hope that you won't have a claustriphobia\n"+
	"attack.\n";
	dest_dir=({
	PPATH + "conn2a","north",
	PPATH + "conn4a","south",
   });
   replace_program("room/room");
}
