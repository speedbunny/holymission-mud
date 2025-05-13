inherit "room/room";

void reset(int arg){
 ::reset(arg);
 if (arg) return;
 set_light(1);
 short_desc=("In the sailor's cottage");
 long_desc=
   "You are in the sailor's cottage. You can see a table with the chairs\n"+
   "in the middle of it and stove in the corner. There are bed and cupboard by\n"+
   "the walls. This cottage is large with two windows. The floor is made of\n"+
   "oak wood and looks clearly.\n";
 smell="You smell salty air";
 items=({"table","Wooden table. It looks old. There is nothing on it",
         "chair","It is made of wood",
         "cupboard","Wooden cupboard. It's closed and don't looks you could\n"+
	  	    "open it",
         "stove","Small stove in the corner",
         "floor","wooden floor. it looks clearly",
         "window","You can see a harbour through it",
         "windows","You can see a harbour through them"
        });
 dest_dir=({ 

	   });
  
}
