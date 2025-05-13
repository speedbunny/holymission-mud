#define PPATH "/players/goldsun/lank/room/"

inherit "/players/goldsun/lank/room/genCoast";

reset(arg){
 ::reset(arg);
 dest_dir=({PPATH + "coast6.c" , "southwest",
	    PPATH + "coast8.c" , "northeast",
	    PPATH + "lank5.c"  , "west",
	    PPATH + "lank3.c"  , "north"});
}


