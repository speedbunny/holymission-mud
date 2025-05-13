inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="The rivers merge here"; 
  long_desc="\nA scattering of flagstones are piled along one side of the riverbank,\n"
            "as two branches of water merge into one here. The main river, wider now,\n"
            "flows mildly downhill to the southwest fed by one branch of water to\n" 
            "the northwest and another from the east. The rock walls tower high over\n"
		"the junction, the river watched over by the birds nesting in the rock.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a10","northwest",
		 "/players/raindell/areas/IWheel/approach/a17","southwest",
		 "/players/raindell/areas/IWheel/approach/a12","east",      
           });

  items=({"rivers","The two rivers merge here and flow towards the southwest", 
          "flagstones","Broken by water and time, many have piled up here on the riverbank",
          "riverbank","Many broken flagstones are strewn about here",
	    "walls","High and craggy, they are home to many birds by the look of the holes in the rock",
	    "junction","The rivers join here",
	    "holes","Apparently birdnests, you can see twigs protruding from many of them",
 	    "water","There is a faint stream of dark silt carried in the water",  
       });

::reset(arg);

   replace_program("/room/room");

}

