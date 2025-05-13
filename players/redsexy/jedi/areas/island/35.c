inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;     

set_light(1);   

short_desc="Inland on a desert island";     
short_desc="Somewhere near the coast in the desert lands of Carkoon"; 
long_desc="You are now walking across the vast plains of sand " + 
              "that spread across the island.  The scenery here is " + 
              "not even worth a mention.  Just sand, everywhere, " +
              "and two menacing hot suns glaring down evilly from " + 
              "the sky.  There are no tracks or footprints of any " + 
              "kind here, and your senses tell you that you are " +
              "safe.  But stories of the sand people dwell in the " + 
              "back of your mind, and you are uncertain of whether " + 
              "to venture further.\n\n";       

dest_dir=({               "/players/redsexy/jedi/areas/island/37.c", "southwest",               
                          "/players/redsexy/jedi/areas/island/36.c", "northeast",          });

items = ({    "view","Sand spreads out in front of you, behind you, everywhere.",            
              "plains","Sand spreads out in front of you, behind you, everywhere.",            
              "island","The whole island is just a sandy desert surrounded by sea.",
              "wind","No wind blows here, and the harsh sunshine burns your skin. ",	    
              "sea","You cannot see the sea from here",	    
              "scenery","Sand spreads out in front of you, behind you, everywhere.",	    
              "sand", "The sand is like cinders, burning your poor feet.",
              "suns", "Two menacing hot suns, burning your skin as they glare upon you.",
              "sun","Two menacing hot suns, burning your skin as they glare upon you.",
              "tracks","There are no tracks of any kind around this place",
	        "footprints","There are no footprints of any kind around this place",
              "sand people","There are no sandpeople here",
              "people","There is no life of any kind to be seen around here",            });
}

void init() {


   ::init();


   add_action("_search","search");

   }



int _search(string str) {


   if(str!="sand") return 0;
   write("You search but find nothing in this hot gritty sand. \n");
   return 1;


   }
