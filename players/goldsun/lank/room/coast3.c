#define PPATH "/players/goldsun/lank/room/"

inherit "/players/goldsun/lank/room/genCoast";

reset(arg){
 ::reset(arg);
 dest_dir=({PPATH + "coast2.c" , "southwest",
	    PPATH + "coast4.c" , "southeast",
	    PPATH + "lank2.c"  , "south"});
}


