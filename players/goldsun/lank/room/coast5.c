#define PPATH "/players/goldsun/lank/room/"

inherit "/players/goldsun/lank/room/genCoast";

reset(arg){
 ::reset(arg);
 dest_dir=({PPATH + "coast1.c" , "northwest",
	    PPATH + "coast6.c" , "southeast",
	    PPATH + "lank1.c"  , "north",
	    PPATH + "lank5.c"  , "east"});
}


