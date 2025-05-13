inherit "room/room";

void reset(int arg){
 ::reset(arg);
 if (arg) return;
 set_light(1);
 short_desc=("In the Hucklebery's cottage");
 long_desc=
   "You are in the Hucklebery's cottage. It isn't large, but there is\n"+
   "enough room for a bed, wooden table with chairs, stove and \n"+
   "cupboard. Through a small window you can see a harbour. Large\n"+
   "fishing nets are hanging from the wooden ceiling.\n";

 smell="You smell salty air";
 items=({"table","Wooden table. It looks old. There is nothing on it",
         "chair","It is made of wood",
         "cupboard","Wooden cupboard. It's closed and don't looks you could\n"+
	  	    "open it",
         "stove","Small stove in the corner",
	 "ceiling","There are fishing nets hanging down from it",
	 "nets","Large fishing nets",
         "net","This fishing net looks new"
        });
 dest_dir=({ 

	   });
  
}
