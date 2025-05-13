#define PPATH "/players/goldsun/lank/room/"

inherit "/players/goldsun/lank/room/genCoast2";

reset(arg){
 ::reset(arg);
 dest_dir=({PPATH + "coast15.c" , "northwest",
	    PPATH + "coast16.c" , "southeast",
	    PPATH + "forest1.c"  , "north",
 	    PPATH + "forest4.c"  , "east"});
}

init(){
 ::init();
add_action("g_east","east");
add_action("g_north","north");
}

g_east(){
 "/players/goldsun/lank/room/forest4"->add_exit("west");
 return ::move("east");
}

g_north(){
 "/players/goldsun/lank/room/forest1"->add_exit("south");
 return ::move("north");
}

