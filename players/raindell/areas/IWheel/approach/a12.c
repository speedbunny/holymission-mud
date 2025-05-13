inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="The eastern branching"; 
  long_desc="\nThere is an odd tint of silt in the water here, which trails downstream\n"
            "in slender whorls of darkness. The canyon walls here seem oddly taller, and\n"
            "the white jagged surfaces are mottled with a strange dark lines. The water\n" 
            "here is cool, but not cold.  Oddly, there is little to no plantlife here,\n"
		"and the absence of the birdsong is notable.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a11","west",
		 "/players/raindell/areas/IWheel/approach/a13","east",      
           });

  items=({"silt","It feels smooth and gritty, and looks rather dark", 
          "water","It looks fairly clear, but the trails of silt are disturbing",
          "walls","Tall, jagged, and white, yet the southern wall is stained with something you can't identify",
	    "lines","From here, the dark crooked lines are unrecognizable",
         });

clone_list=({1,1,"trout","/players/raindell/areas/IWheel/approach/critters/trout",0
              });

::reset(arg);

   replace_program("/room/room");

}

