inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="The river flows downhill and downstream"; 
  long_desc="\nThe water begins to flow faster here as the riverbed leads the way downhill.\n"
            "Though not as high here as elsewhere in the canyon, the rock walls guide the\n"
            "river through the bend to the northwest. Birdsong is again absent from the air\n" 
            "here, and the plants look faintly sickly.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a21","northwest",
             "/players/raindell/areas/IWheel/approach/a19","east",
		});

  items=({"plants","Though green and alive, they have strange patches of brown upon them", 
          "riverbed","It slopes slightly downhill towards the northwest",
          "water","It's crystal-clear and moves quickly, bringing a stain in the water with it",
	    "walls","They aren't so high at this point in the river",
	    "river","It's just short of knee high in depth, and flows to the northwest",
	    "bend","The river arcs to the northwest and then disappears, presumably turning again",
	    "stain","It's dark and sickly looking, carried in the sediment",
	    "sediment","Carried by the river, the loose river-dirt flows along the bottom of the riverbed",   	
 	});

::reset(arg);

   replace_program("/room/room");

}

