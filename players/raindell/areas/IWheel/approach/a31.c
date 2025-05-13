inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="Near the gate"; 
  long_desc="\nYou are standing on a ruined stone path in the canyon. While there is\n"
            "the occasional cry of a bird in the air, your attention is attracted by\n"
            "two things primarily. The first is a large wrought-iron gate to the south,\n"
		"with the second being a strange white aura glowing over the top of the trees\n"
		"in the distance.\n\n";
		          	      
  dest_dir=({"/players/raindell/areas/IWheel/approach/a30","northwest",
		 "/players/raindell/areas/IWheel/approach/a32","south",
             });

  items=({"path","It's overgrown and in obvious disrepair", 
          "canyon","The rock walls of the canyon are not too high, but quite jagged",
          "gate","To the south, there is a sturdy looking iron gate",
	    "aura","You can see an odd white glow peeking over the tops of the trees to the south",
	    "trees","They lie beyond the gate, to the south",
	     	});

::reset(arg);

   replace_program("/room/room");

}
