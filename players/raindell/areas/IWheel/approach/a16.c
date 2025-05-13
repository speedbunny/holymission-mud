inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="The river's source"; 
  long_desc="\nFrom a cluster of fallen rocks in a tight corner of the canyon, a rushing\n"
            "stream of water continually bursts from its underground womb to join the river\n"
            "as it flows quickly downstream to the south. Lush clusters of plantlife thrive\n" 
            "around the edges of the riverbed and a chorus of birdsong can be heard coming\n"
		"from far above you in the cliff.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a15","south",
           });

  items=({"rocks","Though tumbled and fallen, they do not much inhibit the river's course", 
          "corner","The rock walls merge here",
          "canyon","The rock walls stretch into the distance, quite the scenic view really",
	    "water","White and rushing, the water is ice-cold from its time beneath the ground",
          "river","It emerges here from underground and flows quickly to the south",
	    "plantlife","A variety of river plants have taken up root here",
	    "riverbed","It is lined with polished stones, rounded by time and water", 
	    "cliff","High and jagged, you can't really see much from this close angle",  
	});

clone_list=({1,1,"swallow","/players/raindell/areas/IWheel/approach/critters/swallow",0
              });

::reset(arg);

   replace_program("/room/room");

}

