
inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("Private room");
 long_desc="This room is very comfortable. There are wardrobe, bookcase,\n"+
	   "table with chairs in the middle of the room, fireplace on\n"+
	   "the south side and oriental carpet on the floor. On the east\n"+
           "wall you can see a large window and on the other walls\n"+
	   "shields and swords. It is very pleasant to be here.\n";
 
 smell="You smell torch smoke.";

 property=({"has_fire"});

 dest_dir=({"/players/goldsun/nottingham/room/castle/bedroom","north", 
   	    "/players/goldsun/nottingham/room/castle/hall2","west" });

 items=({ "swords","They are fixed to the wall",
          "sword","It is fixed to the wall",
	  "shields","Iron shields with Nottingham sign. They are fixed to the wall",
	  "shield","A shield with Nottingham sign is fixed to the wall",
	  "fireplace","There is a nice fire in it",
	  "carpet","An oriental carpet. It is very soft",
	  "map","There is something written on it",
	  "table","An oak table in the middle of the room. There is a map on it",
	  "chairs","The oak chairs",
	  "chair","An oak chair"
        });

 }
 ::reset(arg);
}
init(){
 ::init();
add_action("read","read");
add_action("do_get","get");
add_action("do_get","take");
}


int read(string str){
 if (str=="map" || str=="map on table" || str=="map on the table"){
  write("You can see on the map:\n"+
	"        Nottingham castle\n"+
        " Ground floor:\n\n"+
        "   X  X  X\n"+
	"   |  |  |\n"+
        "   X--X--X-->town\n"+
        "   |  |  |\n"+
	"   X  X  X\n"+
        " First floor: \n\n"+
        "   X--X\n"+
	"   |\n"+
        "   X--X\n"+
        "   |\n"+
	"   X--X\n"+
        " Second floor: \n\n"+
        "   X--X\n"+
	"   |\n"+
        "   X--X\n"+
        "Third floor:\n\n"+
        "   X\n");
  return 1;
 }
}

int do_get(string str){
    if (str=="map" || str=="map from table"){
     	 write("You are not allowed to do it.\n");
 	 return 1;
    }
}
