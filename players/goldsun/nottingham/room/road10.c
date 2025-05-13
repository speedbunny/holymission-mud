inherit "/players/goldsun/nottingham/room/genRoad";
#include "/obj/door.h"
#define PATH "/players/goldsun/nottingham/room/"

object obj_1,obj_2;

reset(arg){
 object key;

 ::reset(arg);

if (arg) return;

 MAKE_DOORS("/players/goldsun/nottingham/room/road10","east",
          "/players/goldsun/nottingham/room/f_cott","west","steel","fence_code",
          "The door is made of wood.\n",1,0,1);
 
 obj_1->set_door_long("The door is made of wood.\nThere is written \""+
	  	      "Fence School\" on it.\n");

 MAKE_KEY( key, "steel","fence_code");
 
 move_object(key,"/players/goldsun/nottingham/room/tower_ne2");
 obj_1->both_door_sound("A creak sound");
 

 MAKE_DOORS("/players/goldsun/nottingham/room/road10","west",
          "/players/goldsun/nottingham/room/my_cott","east","crystal",
          "30041975", "The door is made of wood.\n", 1,0,1);
 
 obj_1->set_door_long("Wooden door with nice coat-of-arms on it.\nThere is written \""+
	  	      "Sir Goldsun\" on the door.\n");
 
 short_desc="Gos Sun Avenue";

 dest_dir=({ PATH + "road11", "north",
	     PATH + "road9"  , "south" });
}


