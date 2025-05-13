inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="Far downstream"; 
  long_desc="\nStanding knee-deep in the cool river, the water flows past you into the\n"
            "distance, vanishing into an odd concentration of green to the southwest. The\n"
            "air around you echoes musically with birdsong, and the plantlife on the rock\n"
            "walls is flourishing noticeably here. Protruding from the rocks on one side\n"
		"of the canyon and extending to the middle of the river, is a long and very\n"
	      "alive tree branch.\n\n";
                       

  dest_dir=({"/players/raindell/areas/IWheel/approach/a26","southwest",
             "/players/raindell/areas/IWheel/approach/a24","northeast",
		});

  items=({"river","It flows calmly to the southwest", 
          "water","Crisp and cool, you can easily see to the bottom",
          "green","You can't quite make out what this is from here, perhaps if you were closer",
	    "plantlife","The plants are thriving, and cover about half of the canyon wall",
	    "walls","They're half-covered with green, living plants",
	    "rocks","Strange, you wouldn't have thought plants could grow on them",
	    "canyon","The canyon seems to be narrowing to the southwest",
          "branch","It almost seems like an archway, hanging just above your head",
	    "bottom","It's just the riverbed",
	    "riverbed","The river flows through this channel, carved out by time and nature",
	     	});

clone_list=({1,1,"swallow","/players/raindell/areas/IWheel/approach/critters/swallow",0
              });

::reset(arg);

   replace_program("/room/room");

}
