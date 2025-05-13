inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="Approaching the junction"; 
  long_desc="\nWidening a bit here, the river continues to flow calmly on its way.\n"
            "Although the birds are much quieter in this part of the river, the flora\n"
            "is unexpectedly lush, and the water somewhat warmer. Following the river's\n" 
            "course with your eyes, you can see where this branch merges with another\n"
		"to the southeast.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a9","northwest",
		 "/players/raindell/areas/IWheel/approach/a11","southeast",      
           });

  items=({"river","The water is clear and gentle, flowing smoothly to the southeast", 
          "water","It's warm and crystal-clear",
          "flora","There are bright, flowering waterplants along the edge of the river here",
	    "course","The river proceeds to the southeast",
         });

clone_list=({1,1,"bluebird","/players/raindell/areas/IWheel/approach/critters/bluebird",0
              });

::reset(arg);

   replace_program("/room/room");

}

