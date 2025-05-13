#define PPATH "/players/tatsuo/ezo/"
inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(0);
   short_desc = "A small tunnel, full of liquid";
   long_desc = 
	"You are in a small, narrow tunnel. This tunnel is filled with\n"+
	"flourescent liquid from the fountain. Looking south you can see\n"+
	"that the tunnel is sloping upward, promising dry regions. The\n"+
	"room to the west is flooded with water too.\n";
   dest_dir=({
	PPATH + "conn2a","south",
	PPATH + "conn1","west",
   });
   replace_program("room/room");
}
