inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="The darkened corner of the river"; 
  long_desc="\nAs the river flows towards the southwest it rounds this bend, picking up\n"
            "an impure taint of coloring as it does so. A lazy whirlpool rotates in the\n"
            "corner, half-stained by the dark rivulets of liquid that trickle down the\n" 
            "cliff face. The plants brave enough to have their homes here are sickly and\n"
		"wilted, and apart from the river there is a notable absence of sound.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a12","west",
		 "/players/raindell/areas/IWheel/approach/a14","northeast",
           });

  items=({"river","It flows to the southwest and dark tricklings of silt stain the water", 
          "bend","The river slows a bit as it rounds this turning",
          "whirlpool","Like a swirling within a swirling, trails of darkness in clear blue",
	    "corner","The water catches here as it rounds the bend",
	    "rivulets","Dark lines of an unknown liquid scar the cliff face",
	    "liquid","It's dark and looks sticky, but you haven't the slightest desire to touch it to find out more",
	    "face","The cliff, where not stained is an unusual pristine white color",
	    "plants","They are hardly recognizable from the more healthy varieties you have seen",
         });

::reset(arg);

   replace_program("/room/room");

}

