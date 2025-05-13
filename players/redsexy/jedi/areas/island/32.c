inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;     

set_light(1);  

short_desc="Somewhere in the desert lands of Carkoon"; 
long_desc="You are now walking across the vast plains of sand " + 
              "that spread across the island.  The scenery here is " + 
              "not even worth a mention.  Just sand, everywhere, " +
              "and two firey hot suns glaring down evilly from " + 
              "the sky.  There are no tracks or footprints of any " + 
              "kind here, and your senses tell you that you are " +
              "safe.  But stories of the sand people dwell in the " + 
              "back of your mind, and you are uncertain of whether " + 
              "to venture further.\n\n";       

dest_dir=({               "/players/redsexy/jedi/areas/island/16.c", "south",
                          "/players/redsexy/jedi/areas/island/31.c", "north",
                        "/players/redsexy/jedi/areas/island/15.c", "east",            });

items = ({    "view","Sand spreads out in front of you, behind you, everywhere.",            
              "plains","Sand spreads out in front of you, behind you, everywhere.",            
              "island","The whole island is just a sandy desert surrounded by sea.",
              "wind","No wind blows here, and the harsh sunshine burns your skin. ",	    
              "sea","You cannot see the sea from here",	    
              "scenery","Sand spreads out in front of you, behind you, everywhere.",	    
              "sand", "The sand is like cinders, burning your poor feet.",
              "suns", "Two firey hot suns, burning your skin as they glare upon you.",
              "sun","Two firey hot suns, burning your skin as they glare upon you.",
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
   write("Searching hard as you can, you find nothing. \n");
   return 1;


   }
