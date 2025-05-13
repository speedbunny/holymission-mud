#define PPATH "/players/goldsun/lank/room/"

inherit "/players/goldsun/lank/room/genCoast";

reset(arg){
 ::reset(arg);
 dest_dir=({PPATH + "coast5.c" , "northwest",
	    PPATH + "coast7.c" , "northeast",
	    PPATH + "lank5.c"  , "north"});
}


