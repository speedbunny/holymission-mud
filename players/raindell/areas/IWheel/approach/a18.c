inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="A bend in the river"; 
  long_desc="\nAs the river flows around this bend, it heads downhill just slightly\n"
            "before levelling out again, following the course of the riverbed. While\n"
            "the water is still crystal clear, there is still an oddly tainted stream\n" 
            "of silt near the bottom. The canyon walls tower above, still and silent as\n"
		"they witness the passage of the water.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a17","northeast",
             "/players/raindell/areas/IWheel/approach/a19","west",
		});

  items=({"river","The waters are over knee-high on you", 
          "walls","Dotted with nest holes, the walls are rocky and strangely silent.",
          "water","While crystal-clear, the dark stream of silt near the bottom is bothersome",
	    "riverbed","It's formed of time polished rock and scattered broken flagstones",
          "stream","A dark trail of silt flows beneath the water"
	    "silt","This loose sediment is quite unusual looking, being a different color than the riverbed",		
    		});

clone_list=({1,1,"trout","/players/raindell/areas/IWheel/approach/critters/trout",0
              });

::reset(arg);

   replace_program("/room/room");

}

