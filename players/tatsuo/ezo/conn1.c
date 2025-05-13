#define PPATH "/players/tatsuo/ezo/"
inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(0);
   short_desc = "A small tunnel, full of liquid";
   long_desc = 
	"You are in a small, narrow tunnel. This tunnel is filled with\n"+
	"flourescent liquid from the fountain. Looking north you can see\n"+
	"that the tunnel is sloping upward, promising dry regions, to the\n"+
	"south is a hole and to the east the tunnel leads on underwater.\n";
   dest_dir=({
	PPATH + "conn2","north",
	PPATH + "conn1a","east",
	PPATH + "inFount","south",
   });
   replace_program("room/room");
}
