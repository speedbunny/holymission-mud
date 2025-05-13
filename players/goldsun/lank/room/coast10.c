#define PPATH "/players/goldsun/lank/room/"

inherit "/players/goldsun/lank/room/genCoast2";

reset(arg){
 ::reset(arg);
 dest_dir=({PPATH + "coast9.c" , "southwest",
	    PPATH + "coast11.c" , "southeast",
	    PPATH + "forest2.c"  , "south"});
}

init(){
 ::init();
add_action("g_south","south");
}

g_south(){
 "/players/goldsun/lank/room/forest2"->add_exit("north");
return ::move("south");
}
