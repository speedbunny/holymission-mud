inherit "room/room";

void reset(int arg){
 ::reset(arg);
 if (arg) return;
 set_light(1);
 short_desc=("Billy's cottage");
 long_desc=
   "You are in the Billy's cottage. You can see a table with the chairs\n"+
   "in the middle of it and stove in the corner. There is a net by the wall.\n"+
   "The net is fixed on its ends to the walls. Billy uses it for sleeping.\n"+
   "In front of small window is a large cupboard.\n";

 smell="You smell salty air";
 items=({"table","Wooden table. It looks old. There is nothing on it",
         "chair","It is made of wood",
         "cupboard","Wooden cupboard. It's closed and don't looks you could\n"+
	  	    "open it",
         "stove","Small stove in the corner",
         "net","It is right sailor bed",
         "window","You see a harbour through it",
	 "wall","It's made of wood. The net is fixed on it"
        });
 dest_dir=({ 

	   });
  
}
