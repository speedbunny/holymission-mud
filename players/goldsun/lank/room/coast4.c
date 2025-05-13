#define PPATH "/players/goldsun/lank/room/"

inherit "/players/goldsun/lank/room/genCoast";

object cottage;

reset(arg){
 ::reset(arg);

 if (arg) return;

 move_object("/players/goldsun/lank/obj/cott",this_object());

 dest_dir=({PPATH + "coast3.c" , "northwest",
	    PPATH + "coast8.c" , "southeast",
	    PPATH + "lank2.c"  , "west",
	    PPATH + "lank3.c"  , "south" });
}


