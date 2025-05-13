inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="Heading upstream"; 
  long_desc="\nThe river flows faster as it comes down the slope from the southwest\n"
            "southwest, slowing as it widens and moves through the bend opposite.\n"
            "There are fewer plants alongside the river here and the birdsong has\n" 
            "diminished signifigantly. You can, however, hear a deep rumbling coming\n"
            "from farther upstream.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a7","southwest",
		 "/players/raindell/areas/IWheel/approach/a5","northeast",      
           });

  items=({"river","Though faster and tipped with white, the waters can still be safely traversed", 
          "slope","Not too steep really, you can still move uphill if you tread carefully",
          "bend","The river turns and widens as it flows to the northeast",
	    "plants","The waterplants are fewer in number here",
	    "upstream","It seems the river slopes upwards sharply to the southwest",                  
         });

clone_list=({1,1,"kestral","/players/raindell/areas/IWheel/approach/critters/kestral",0
              });

::reset(arg);

   replace_program("/room/room");

}

