inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;     

set_light(1);     

short_desc="Somewhere near the coast in the desert lands of Carkoon"; 

long_desc="You walk slightly away from the coast, the smell " +
              "and the sound of the sea still in your senses, but " +
              "sand the only thing you can see.  You imagine it " +
              "would be easy to get lost in a place like this, with " +
              "no landmarks, but being a skilled adventurer you know you " +
              "can rely on the sun should you get lost.\n\n";    

dest_dir=({               "/players/redsexy/jedi/areas/island/35.c", "southwest",
                          "/players/redsexy/jedi/areas/island/7.c", "north",
                          "/players/redsexy/jedi/areas/island/9.c", "southeast",     });

items = ({    "view","Sand spreads out in front of you, behind you, everywhere.",            
              "plains","Sand spreads out in front of you, behind you, everywhere.",            
              "island","The whole island is just a sandy desert surrounded by sea.",
              "wind","No wind blows here, and the harsh sunshine burns your skin. ",	    
              "sea","You cannot see the sea from here,but you can hear it and smell it",	    
              "scenery","Sand spreads out in front of you, behind you, everywhere.",	    
              "sand", "The sand is like cinders, burning your poor feet.",
              "suns", "Two scorching hot suns, burning your skin as they glare upon you.",
              "sun","Two scorching hot suns, burning your skin as they glare upon you.",
              "tracks","There are no tracks of any kind around this place",
	      "footprints","There are no footprints of any kind around this place",
              "coast","From the sound of the sea the coast is near to here",
              "landmarks","There are no landmarks here",
            });
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
