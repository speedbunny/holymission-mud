#define PPATH "/players/goldsun/lank/room/"

inherit "/players/goldsun/lank/room/genCoast2";
reset(arg){
 ::reset(arg);
 dest_dir=({PPATH + "coast15.c" , "southwest",
	    PPATH + "coast10.c" , "northeast",
	    PPATH + "forest1.c"  , "south",
 	    PPATH + "forest2.c"  , "east"});
}

init(){
 ::init();
add_action("g_east","east");
add_action("g_south","south");
}

g_east(){
  "/players/goldsun/lank/room/forest2"->add_exit("west");
 return ::move("east");
}

g_south(){
  "/players/goldsun/lank/room/forest1"->add_exit("north");
return ::move("south");
}


