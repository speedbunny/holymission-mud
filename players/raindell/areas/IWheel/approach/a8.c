inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="The waterfall"; 
  long_desc="\nThe sheer noise here is more than matched by raw, primitive beauty.\n"
            "You stand on a thin ledge of jagged stone which appears to be the only\n"
            "solid ground in sight. Before you is an impressively high waterfall, the\n" 
            "obvious origin of the river you have been treading through. Thunderously\n"
		"pouring over the edge, the water casts a rainbow-colored spray over the\n"
		"lush and abundant plantlife on the rock walls, gathering in a wide pool\n"
		"before heading downstream.\n\n";
           
 
  items=({"ledge","Though rocky and sharp, it still looks like you could 'cross' to go back the way you came", 
          "ground","You're standing on it, but there's precious little",
          "stone","The stone ledge is rather sharp and jagged",
	    "waterfall","Tall and majestic, the water thunders down the cliff into the pool below",
	    "river","You can see part of the river from here, but little else as the rock walls are too high",                  
	    "water","The falls are quite impressive",	
	    "spray","The entire area is covered with this cool mist",
	    "plantlife","Water-fed flowering vines climb and cling to the walls here",
	    "pool","It looks quite deep actually, but you can't see the bottom",
	    "mist","The entire area is covered with this cool mist",
	    "vines","You can hardly see the rock walls through them",
	    "walls","Completely covered in vines",
         });

}

void init() {

   ::init();

   add_action("_cross","cross");
 }
     int _cross(string str) {
     if(str!="ledge") return 0;
     write("You carefully pick your way across the ledge.\n");
     this_player()->move_player("carefully across the ledge.#players/raindell/areas/IWheel/approach/a7.c");

   return 1;

   }
