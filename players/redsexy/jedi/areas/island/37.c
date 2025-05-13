inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;     

set_light(1);    

short_desc="A dangerous place on the island";     

long_desc="You are now walking across the vast plains of sand that spread " + 
              "across the island.  The scenery here is not even worth a mention.  " +  
              "Just sand, everywhere, and two scorching hot suns glaring down evilly " + 
              "from the sky.  The tracks here indicate that this may be one of the " +
              "hunting grounds of the sandpeople, and so you exercise caution in " +
              "choosing which way to turn next.\n\n";
    dest_dir=({               "/players/redsexy/jedi/areas/island/34.c", "northwest",               
                              "/players/redsexy/jedi/areas/island/35.c", "northeast",               
                              "/players/redsexy/jedi/areas/island/38.c", "south", 
                              "/players/redsexy/jedi/areas/island/5.c", "north",     });

items = ({    "view","Sand spreads out in front of you, behind you, everywhere.",            
              "plains","Sand spreads out in front of you, behind you, everywhere.",            
              "island","The whole island is just a sandy desert surrounded by sea.",
              "wind","No wind blows here, and the harsh sunshine burns your skin. ",	    
              "sea","You cannot see the sea from here",	    
              "scenery","Sand spreads out in front of you, behind you, everywhere.",	    
              "sand", "The sand is like cinders, burning your poor feet.",
              "suns", "Two scorching hot suns, burning your skin as they glare upon you.",
              "sky", "The sky is a deep red, blushed by the suns",
              "sun","Two scorching hot suns, burning your skin as they glare upon you.",
              "tracks","The tracks here are indicative of sand people hunting in the area",
              "footprints","The footprints here are indicative of sand people hunting in the area",
              "sand people","There are no sandpeople here",
              "people","There is no life of any kind to be seen around here",            });
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
