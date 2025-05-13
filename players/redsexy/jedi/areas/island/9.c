inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;     

set_light(1);     
short_desc="A scorching hot place on the coastline of the island.";     

long_desc="The sun starts to burn your skin as you" +
          " look over the coastline of this arrid island." +
          " A slight hardening of the sand makes a path" +
          " of sorts which leads inland, and to the south" +
          " the shore continues.\n\n";    

dest_dir=({              "/players/redsexy/jedi/areas/island/10.c", "south",        
                         "/players/redsexy/jedi/areas/island/36.c", "northwest",              
                         "/players/redsexy/jedi/areas/island/8.c", "north",     
          });

items = ({  "view","The sea spreads out in front of you, like a blanket of blue",
            "waves","These waves powerful and dangerous.",            
            "sand","The sand is very hot beneath your feet",           
            "path","A few sets of tracks that lead inland make a path",
            "tracks","The tracks lead to the northeast",	    
            "sea","The sea leaves you spellbound. Never before has nature been so powerful",	    
            "dune sea","The sea leaves you spellbound. Never before has nature been so powerful",	    
            "spray", "The spray tastes salty against your lips, and dampens your hair slightly",
            "shore","The sea meets the sand with a crashing sound",
            "coast","The sea meets the sand with a crashing sound",
            "coastline","The sea meets the sand with a crashing sound",
            "skin","Your skin is chaffed by the harsh warmth of the sun",
            });

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
