inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;

set_light(1);     

short_desc=   "The continuing shoreline of the island";     

long_desc=    "Continuing along the shore you wonder if you will " +
              "ever see any sign of life again, or if you will die " +
              "in this trecherous place.  There is no way to venture " +
              "inland - the heat prevents you from leaving the shore, " +
              "where there is at least a breeze blowing from the sea\n\n";

dest_dir=({              "/players/redsexy/jedi/areas/island/19.c", "south",    
                         "/players/redsexy/jedi/areas/island/21.c", "northwest",     });

items = ({    "view","Sand spreads out in front of you, behind you, everywhere.",            
              "plains","Sand spreads out in front of you, behind you, everywhere.",            
              "island","The whole island is just a sandy desert surrounded by sea.",
              "wind","A little breeze blows here, bringing relief from the harsh sun",	    
              "breeze","A little breeze blows here, bringing relief from the harsh sun",	    
              "sea","The sea rises quite calmly against the shore here",	    
              "scenery","Sand and sea are all you see.",	    
              "sand", "Everywhere you look, just sand",
              "desert","Everywhere you look, just sand",
              "suns", "Two scorching hot suns, burning your skin as they glare upon you.",
              "sun","Two scorching hot suns, burning your skin as they glare upon you.",
           
  });
}

void init() {


   ::init();


   add_action("_search","search");

   }



int _search(string str) {


   if(str!="sand") return 0;
   write("You furrow through the sand methodically, but there is no hidden treasure here. \n");
   return 1;


   }
