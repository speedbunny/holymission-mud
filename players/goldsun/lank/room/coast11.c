#define PPATH "/players/goldsun/lank/room/"

inherit "/players/goldsun/lank/room/genCoast2";

reset(arg){
 ::reset(arg);
 dest_dir=({PPATH + "coast12.c" , "southeast",
	    PPATH + "coast10.c" , "northwest",
	    PPATH + "forest3.c"  , "south",
 	    PPATH + "forest2.c"  , "west"});
}
init(){
 ::init();
add_action("g_west","west");
add_action("g_south","south");
}

g_south(){
 "/players/goldsun/lank/room/forest3"->add_exit("north");
 return ::move("south");
}

g_west(){ 
 "/players/goldsun/lank/room/forest2"->add_exit("east");
 return ::move("west");
}

