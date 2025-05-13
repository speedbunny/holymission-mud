#define PPATH "/players/tatsuo/ezo/"
inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(0);
   short_desc = "Under a tree";
   long_desc = 
        "You are in a cave under a tree. It is a quite large chamber, so\n"+
        "you can move around easily. Roots support the walls of this room\n"+
        "so you do not have to fear a cave-in. To the north is a narrow\n"+
        "tunnel you can go up in something that seems like a hollow tree.\n"+
        "A ladder is fixed at the wall, leading up.\n";
   dest_dir=({
	PPATH + "conn5a","north",
	PPATH + "conn7a","up",
   });
   replace_program("room/room");
}
