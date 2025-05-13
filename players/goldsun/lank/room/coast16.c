#define PPATH "/players/goldsun/lank/room/"

inherit "/players/goldsun/lank/room/genCoast2";

reset(arg){
 ::reset(arg);
 dest_dir=({PPATH + "coast14.c" , "northwest",
	    PPATH + "coast13.c" , "northeast",
	    PPATH + "coast17.c" , "south",
	    PPATH + "forest4.c" , "north"});
}
init(){
 ::init();
add_action("g_north","north");
}

g_north(){
 "/players/goldsun/lank/room/forest4"->add_exit("south");
 return ::move("north");
}

