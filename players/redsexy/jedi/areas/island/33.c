inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;     

set_light(1);     

short_desc="A lonley place on the island";     

long_desc="The lack of life on this island, the vastness and " +
              "emptiness of everything you have seen leaves a deep " +
              "rooted sense of lonliness as you venture onward.  " +
              "The sun makes you hot and bothered, and you wonder " +
              "why you came here in the first place\n\n";  
  
dest_dir=({               "/players/redsexy/jedi/areas/island/26.c", "southwest",               
                          "/players/redsexy/jedi/areas/island/34.c", "north",          });

items= ({    "view","Sand spreads out in front of you, behind you, everywhere.",            
              "plains","Sand spreads out in front of you, behind you, everywhere.",            
              "island","The whole island is just a sandy desert surrounded by sea.",
              "wind","No wind blows here, and the harsh sunshine burns your skin. ",	    
              "sea","You cannot see the sea from here",	    
              "scenery","Sand spreads out in front of you, behind you, everywhere.",	    
              "sand", "The sand is like cinders, burning your poor feet.",
              "suns", "Two scorching hot suns, burning your skin as they glare upon you.",
              "sun","Two scorching hot suns, burning your skin as they glare upon you.",
              "tracks","There are no tracks of any kind around this place",
	      "footprints","There are no footprints of any kind around this place",
              "life","There is no life of any kind to be seen around here",            });
}


void init() {


   ::init();


   add_action("_search","search");

   }



int _search(string str) {


   if(str!="sand") return 0;
   write("You furrow through the sand methodically,\n" + "but there is no hidden treasure here. \n");
   return 1;


   }
