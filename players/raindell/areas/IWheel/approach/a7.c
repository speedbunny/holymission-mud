inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="Dangerously fast waters"; 
  long_desc="\nThis is about as far as you dare go in the river itself. Immediately\n"
            "to the southwest the riverbed is quite steep, and the waters dash down\n"
            "with abandon. There seems however, to be a ledge of rock protruding from\n" 
            "one of walls. Perhaps the answer lies there.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a6","northeast",      
           });

  items=({"river","The waters run rough and swift, pouring down from the southwest", 
          "riverbed","Beyond this point the riverbed is shallow and dangerously steep",
          "waters","They are white-tipped, swift, and violent",
	    "ledge","It's narrow and jagged but it looks like you could 'cross' it",
	    "rock","Rocky and sharp, but it looks like you could cross this ledge",                  
	    "walls","They are losing height the farther you go",	
         });

  clone_list=({1,1,"trout","/players/raindell/areas/IWheel/approach/critters/trout",0
              });

::reset(arg);

}

void init() {

   ::init();

   add_action("_cross","cross");
 }
     int _cross(string str) {
     if(str!="ledge") return 0;
     write("You carefully pick your way across the ledge.\n");
     this_player()->move_player("carefully across the ledge.#players/raindell/areas/IWheel/approach/a8.c");

   return 1;

   }
