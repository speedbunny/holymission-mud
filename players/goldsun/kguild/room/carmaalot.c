inherit "room/room";

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="Carmaalot castle";
        long_desc=
   "You are standing behind the gates of Carmaalot castle.\n"+
   "The castle is made of shiny white stone. A nice river runs\n"+
   "around this castle.\n";
	    

     dest_dir=({"/players/goldsun/lank/room/forest1","west",
	      "/players/goldsun/lank/room/forest2","north",
      	      "/players/goldsun/lank/room/forest3","east",
              "/players/goldsun/lank/room/forest4","south"});
        items=({ 
            "castle","@@short",   /* we need that to get the 'castle' id */
	    "river","Nice blue river",
	    "stone","White shiny stone",
	    "gates","The gates are open"
              });

    }
}

init() {
    ::init();

 add_action("enter", "enter");
 add_action("g_north","north");
 add_action("g_south","south");
 add_action("g_west","west");
 add_action("g_east","east");
 
}

g_north(){
 "/players/goldsun/lank/room/forest2"->add_exit("south");
 return ::move("north");
}

g_south(){
 "/players/goldsun/lank/room/forest4"->add_exit("north");
 return ::move("south");
 }

g_east(){
 "/players/goldsun/lank/room/forest3"->add_exit("west");
 return ::move("east");
 }

g_west(){
 "/players/goldsun/lank/room/forest1"->add_exit("east");
 return ::move("west");
}

enter(str) {
  if (str=="castle" || str=="gates"){
    this_player()->move_player("though the gates#/players/goldsun/guild/room/hall");
    return 1;}
  else write("Enter what ?\n");
  return 1;
}
