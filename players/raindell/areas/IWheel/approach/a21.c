inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="The tainted bend"; 
  long_desc="\nAs the river flows downhill and curves around the bend to the southwest, the\n"
            "water catches and swirls behind a large pile of broken flagstones, forming an\n"
            "odd-looking whirlpool. The plantlife around the whirlpool is dead or dying,\n" 
            "and birdsong is noteably absent from the air, despite the visible nest holes\n"
            "in the canyon wall.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a22","southwest",
             "/players/raindell/areas/IWheel/approach/a20","southeast",
		});

  items=({"river","Slightly shallower here, the river continues to flow downstream to the southwest", 
          "bend","The river arcs to the southwest around a large mound of broken flagstones",
          "flagstones","Shattered and broken, they have been swept here by the current, where they have piled up",
	    "whirlpool","The swirling of water has a disturbing dark color within",
	    "plantlife","It is sickly and blackened, down to the very last leaf",
	    "holes","Though obviously nesting grounds, no sign of life comes from them",
	    "wall","The southern canyon wall seems to be getting slightly lower here",
	    	});

clone_list=({1,1,"trout","/players/raindell/areas/IWheel/approach/critters/trout",0
              });

::reset(arg);

   replace_program("/room/room");

}

