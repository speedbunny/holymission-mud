inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="The warm place in the water"; 
  long_desc="\nThere is an odd warmth to the water here as it flows lazily from the east\n"
            "to the west, and the plantlife seems to be more lush and plentiful. There is\n"
            "even an odd echo of birdsong ringing off the cliffs. The water level is just\n" 
            "slightly lower as the river flows downhill to the west.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a18","east",
             "/players/raindell/areas/IWheel/approach/a20","west",
		});

  items=({"plantlife","It's quite plentiful here, and looks mostly healthy", 
          "cliffs","Birds apparently roost high above, from the sound of things",
          "water","While crystal-clear, the dark stream of silt near the bottom troubles you greatly",
	    "river","It's just below knee high, and flows downhill to the west",
        	});

clone_list=({1,1,"kestral","/players/raindell/areas/IWheel/approach/critters/kestral",0
              });

::reset(arg);

   replace_program("/room/room");

}

