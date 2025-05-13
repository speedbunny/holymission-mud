inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="On the ruined path"; 
  long_desc="\nThe path here is overgrown and ruined, covered with scrub grass and bits\n"
            "of assorted rubble. The canyon walls are lower here, and hug the trail all\n"
            "along the way. To the west you can hear faint sounds that could be a river.\n\n";
          	      
  dest_dir=({"/players/raindell/areas/IWheel/approach/a28","northwest",
		 "/players/raindell/areas/IWheel/approach/a30","east",
             });

  items=({"path","You can only see where it used to be, by the half-buried pieces of flagstone", 
          "grass","It's brown and ragged looking",
          "rubble","It's mostly fallen rocks from the walls above",
	    "walls","The canyon walls are jagged, but not so high",
	    "trail","It's only faintly visible",
	    "flagstones","The once proud slabs of stone are broken and mostly buried under dirt and rubble",
	     	});

::reset(arg);

   replace_program("/room/room");

}
