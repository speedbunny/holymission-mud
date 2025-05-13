inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;     

set_light(1);     

short_desc="Somewhere strange in the desert lands of Carkoon"; 

long_desc="The sand is softer under your feet here, as " +
          "if it could almost give way to reveal something " +
          "underneath.  Particularly in the north, the sand " +
          "seems to hide something, but the heat of the sun " +
          "prevents you from travelling that way directly.\n\n";    

dest_dir=({               "/players/redsexy/jedi/areas/island/39.c", "southwest",              
                          "/players/redsexy/jedi/areas/island/12.c", "east",     });

items = ({    "view","Sand spreads out in front of you, behind you, everywhere.",            
              "plains","Sand spreads out in front of you, behind you, everywhere.",            
              "island","The whole island is just a sandy desert surrounded by sea.",
              "wind","No wind blows here, and the harsh sunshine burns your skin. ",	    
              "sea","You cannot see the sea from here",	    
              "scenery","Sand spreads out in front of you, behind you, everywhere.",	    
              "sand", "The sand seems to be covering something to the north",
              "suns", "Two scorching hot suns, burning your skin as they glare upon you.",
              "sun","Two scorching hot suns, burning your skin as they glare upon you.",
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
   write("You notice the sand in the north is particuarly soft, but there is nothing you can do from here! \n");
   return 1;


   }
