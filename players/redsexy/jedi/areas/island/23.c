inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {
if (arg) return;     

set_light(1);     
short_desc="The western tip of the island";     
long_desc="You stand on the western tip of the island, gazing out over " + 
          "the sea.  You have almost forgotten what vegetation looks like, " +
          "and strain to see what lies beyond the horizon, but can make out " +
          "nothing but the putrid waters and the sand around you.\n\n";    

dest_dir=({              "/players/redsexy/jedi/areas/island/22.c", "southeast",
                         "/players/redsexy/jedi/areas/island/24.c", "northeast",     });

items = ({            "view","The sea spreads out in front of you, like a blanket of blue",
                      "waves","These waves powerful and dangerous.",	    
                      "wind","Harsh and cold, the wind howls across the sea.",	    
                      "sea","The sea is a mirky green here",
                      "dune sea","The sea is a mirky green here",
                      "spray", "The spray tastes salty against your lips, and dampens your hair slightly",
                     "horizon","Just a line of sea, no sign of life at all",
                     "waters","The sea is a mirky green, smelly and putrid",
              	   "water","The sea is a mirky green, smelly and putrid",           
                     "sand","Miles of sand that spread on forever",            });
}

void init() {


   ::init();


   add_action("_search","search");

   }



int _search(string str) {


   if(str!="sand") return 0;
   write("You search as hard as you can, but there is nothing to search for. \n");
   return 1;


   }
