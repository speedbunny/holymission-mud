inherit "/room/room";
#include "/obj/door.h"

object obj_1,obj_2;

reset(arg){
 ::reset(arg);

 if (arg) return;
 set_light(1);
 short_desc="A fence school";
 long_desc="You are in the fencing school. Wooden floor and walls give this\n"+
	   "room a cozy feel. On the walls you can see many weapons.\n";
 no_obvious_msg="";

 MAKE_DOORS("/players/goldsun/nottingham/room/f_cott","south",
	   "/players/goldsun/nottingham/room/f_school","north",
	   "copper","fighting",
	   "Wooden door with a wooden fighter set into it.\n",
	   1,0,0);

	
 smell="You smell a wooden odour";
 items=({"floor","It is made of teak wood",
	 "walls","They are made of teak wood",
	 "weapons","Many kind of weapons. They look old",
	 "weapon","An old sword of Knight Mayan"});
}
