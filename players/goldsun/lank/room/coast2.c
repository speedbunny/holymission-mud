#define PPATH "/players/goldsun/lank/room/"

inherit "/players/goldsun/lank/room/genCoast";

reset(arg){
 ::reset(arg);
 dest_dir=({PPATH + "coast1.c" , "southwest",
	    PPATH + "coast3.c" , "northeast",
	    PPATH + "lank1.c"  , "south",
 	    PPATH + "lank2.c"  , "east"});
}


