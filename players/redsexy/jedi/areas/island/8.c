inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;     

set_light(1);     

short_desc="A peaceful place on the coastline of the island.";     

long_desc="The extremes of nature meet as one as you" +
          " continue following the coastline.  The sun" +
          " is searing, the waves are thrashing, yet all" + 
          " around everything is peaceful.\n\n";    

dest_dir=({              "/players/redsexy/jedi/areas/island/9.c", "south",              
                         "/players/redsexy/jedi/areas/island/7.c", "northwest",                   
          });

items = ({            "view","The sea spreads out in front of you, like a blanket of blue",            
                      "waves","These waves are powerful and dangerous.",            
                      "coast","The monotonous coast of the island.",                          
                      "coastline","The monotonous coast of the island.",              
			    "wind","Harsh and cold, the wind howls across the sea.",	    
                      "sea","The sea leaves you spellbound. Never before has nature been so powerful",	    
                      "dune sea","The sea leaves you spellbound. Never before has nature been so powerful",	    
                      "spray", "The spray tastes salty against your lips, and dampens your hair slightly",
                      "sun","The heat from the suns is searingly hot",            });

}

void init() {

   ::init();

   add_action("search","search");

   }



int search(string str) {

   if(str!="sand") return 0;

   write("You search the sand and find nothing. \n");

   return 1;

   }

