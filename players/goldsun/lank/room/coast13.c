#define PPATH "/players/goldsun/lank/room/"

inherit "/players/goldsun/lank/room/genCoast2";

reset(arg){
 ::reset(arg);
 dest_dir=({PPATH + "coast16.c" , "southwest",
	    PPATH + "coast12.c" , "northeast",
	    PPATH + "forest3.c"  , "north",
 	    PPATH + "forest4.c"  , "west"});
}

init(){
 ::init();
add_action("g_west","west");
add_action("g_north","north");
}

g_north(){
 "/players/goldsun/lank/room/forest3"->add_exit("south");
return ::move("north");
}

g_west(){
 "/players/goldsun/lank/room/forest4"->add_exit("east");
return ::move("west");
}

