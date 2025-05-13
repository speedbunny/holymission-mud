inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="Far upstream"; 
  long_desc="\nThis far upstream the river begins to narrow significantly, its width\n"
            "constricted by the close walls of jagged rock.  While the water does flow\n"
            "faster here, it is not dangerously so, and you could proceed upstream from\n" 
            "here with a minimum of difficulty.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a14","southwest",
		 "/players/raindell/areas/IWheel/approach/a16","north",
           });

  items=({"river","About shin-high here, it flows towards the southwest quickly", 
          "water","It's quite clear, even while moving quickly",
          "walls","Closer together here, they tighten the flow of the river",
	    "rock","Rough and jagged, you don't even want to think about climbing this",
         });

::reset(arg);

   replace_program("/room/room");

}

