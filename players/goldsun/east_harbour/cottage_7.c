inherit "room/room";

void reset(int arg){
 ::reset(arg);
 if (arg) return;
 set_light(1);
 short_desc=("Hook's cottage");
 long_desc=
   "You are in the Hook's cottage. You can see a table with the chairs\n"+
   "in the middle of it and stove in the corner. There is a net by the wall.\n"+
   "The net is fixed on its ends to the walls. In front of small windows\n"+
   "is a large cupboard. There is a nice model of ship on it.\n";


 smell="You smell salty air";
 items=({"table","Wooden table. It looks old. There is nothing on it",
         "chair","It is made of wood",
         "cupboard","Wooden cupboard. It's closed and don't looks you could\n"+
	  	    "open it. There is a nice model of ship on it",
         "stove","Small stove in the corner",
         "net","It is right sailor bed",
         "window","You can see a harbour through it",
         "windows","You can see a harbour through them",
	 "wall","It's made of wood. The net is fixed on it",
         "ship","A model of ship. Maybe Hook is captain on it",
         "model","A model of ship. maybe Hook is captain on it"
        });
 dest_dir=({ 

	   });
  
}
