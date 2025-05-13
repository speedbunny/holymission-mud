inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="On the ruined path"; 
  long_desc="\nWalking through the canyon here, you are struck by the utter and eerie\n"
            "silence of this place. It is almost like nature is holding a continual\n"
            "soundless requiem for something precious gone past. The canyon walls are\n"
		"not so high here, and the path can be seen extending to the west and the\n"
		"southeast.  Just around the southeastern corner of the path, you can see\n"
		"a faint white glow upon the horizon.\n\n";
          	      
  dest_dir=({"/players/raindell/areas/IWheel/approach/a29","west",
		 "/players/raindell/areas/IWheel/approach/a31","southeast",
             });

  items=({"canyon","The walls are fairly narrow here, though not too high", 
          "walls","They are rocky, but not terribly awe-inspiring",
          "path","Ruined and overgrown, you can make out an occasional broken fragment of flagstone",
	    "glow","It's vaguely white",
	    "horizon","There is an odd glow against the sky to the southeast",
	    "flagstone","Bits of it can be seen half-buried in the ground",
	     	});

::reset(arg);

   replace_program("/room/room");

}
