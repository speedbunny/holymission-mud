inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="Just southwest of the junction"; 
  long_desc="\nRejuvenated by the merging to the northeast, the river runs calm but true\n"
            "on its journey through the canyon. Though the water is now over your knees,\n"
            "it still seems you can proceed so long as you're careful. The plants along\n" 
            "the river's edge appear to be thriving, but there is a strange absence of\n"
		"birdsong in this part of the canyon.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a11","northeast",
             "/players/raindell/areas/IWheel/approach/a18","southwest",
		});

  items=({"river","It seems wider and deeper here, fed by two waterways now", 
          "canyon","It stretches all around, you can see little else",
          "water","The water is over knee-deep, and has a faint trail of dark silt running through it",
	    "plants","The appear healthy, apart from an odd brown streaking under the leaves",
          "edge","The plants grow here quite handily",
	    "silt","It's quite unusual looking, being a different color than the riverbed",		
    	    "leaves","They look faintly wrong to your eyes",
		});

::reset(arg);

   replace_program("/room/room");

}

