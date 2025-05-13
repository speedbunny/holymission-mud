inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="Upstream in the river"; 
  long_desc="\nThe water is cold as it flows past your legs, and birdsong rings\n"
            "eerily off the high rock walls.  High overhead, the sun seems to be\n"
            "the only witness to your passage here. Strangely, even though you\n" 
            "stand in the chilled water, you feel quite comfortable. Plants still\n"
            "line the edges of the river, though they look brighter somehow.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a5","northwest",
		 "/players/raindell/areas/IWheel/approach/a3","southeast",      
           });

  items=({"water","The water is clear and cold, yet shimmers unusually here", 
          "walls","The high jagged rock looks as if it's been here forever",
          "sun","You turn away after gazing for a moment",
	    "plants","The waterplants are actually in bloom here and their leaves seem greener",
	    "leaves","They lie on the surface of the water and soak up the sun",                  
        });

clone_list=({1,1,"trout","/players/raindell/areas/IWheel/approach/critters/trout",0
              });


::reset(arg);

   replace_program("/room/room");

}

