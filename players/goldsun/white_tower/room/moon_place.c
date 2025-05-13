inherit "/room/room";
#define TP this_player()

reset(arg){

if (!arg){

 set_light(1);
 short_desc=("A moony place");
 long_desc=
   "You stand on the moony place at the end of Moon valley. There is\n"+
   "very nice White Tower in the middle. You can see tall rocky peaks\n"+
   "to the north, west and south. Valley continues to the east.\n";
   
 smell="The air smells dusty here";

 dest_dir=({ "/players/goldsun/white_tower/room/vall_road",   "east"});
 
 items=({ "valley","Moon valley to the east",
	  "place",long_desc,
	  "peaks","The peaks are round this place. Only to the east is a"+
	          " small passage",
          "tower","Beautiful tower made of white marble. There is wooden"+
                  "door in it",
	  "door","Wooden door with a painting of three rings on it"
	  });
  }
 ::reset(arg);

}

init(){
 ::init();
 add_action("enter","enter");
 add_action("open","open");
}

int open(string str){
  if (str=="door"){
    write("Try enter it. If you are the right adventurer you can pass.\n");
    return 1;
  }
}

int enter(string str){
  notify_fail("Enter what?\n");
  if (str=="door" || str=="tower" || str=="white tower"){
    if (  present("white_tower_g_ring_1",TP) &&
          present("white_tower_g_ring_2",TP) &&
          present("white_tower_g_ring_3",TP)){
       TP->move_player("into the tower#players/goldsun/white_tower/room/inside");
       return 1;
    }
    write("Door says: You are not allowed to enter. Only mighty guards can.\n");
    return 1;
  }
}

