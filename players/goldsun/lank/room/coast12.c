#define PPATH "/players/goldsun/lank/room/"

inherit "/players/goldsun/lank/room/genCoast2";

reset(arg){
 ::reset(arg);
 dest_dir=({PPATH + "coast13.c" , "southwest",
	    PPATH + "coast11.c" , "northwest",
 	    PPATH + "forest3.c"  , "west"});
}

init(){
 ::init();
add_action("g_west","west");
}

g_west(){
 "/players/goldsun/lank/room/forest3"->add_exit("east");
 return ::move("west");
}

