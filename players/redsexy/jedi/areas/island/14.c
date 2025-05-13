inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;     
set_light(1);      

short_desc=   "A long stretch of coast on the island";     
long_desc=    "The two suns beat down on you without mercy as you continue " +
              "exploring this island.  The sand is white, bleached by the  " +
              "relentless rays, and in your mind the froth of the sea becomes " +
              "boiling globs of water, ready to scorch your body if you dared " +
              "to enter.  This long stretch of coastline continues southwestward " +
              "and you feel you have nothing to fear around here. \n\n";     

dest_dir=({           "/players/redsexy/jedi/areas/island/30.c", "northwest",
                      "/players/redsexy/jedi/areas/island/15.c", "southwest",
                      "/players/redsexy/jedi/areas/island/13.c", "northeast",     });

items = ({    "view","Sand spreads out in front of you, behind you, everywhere.",            
              "plains","Sand spreads out in front of you, behind you, everywhere.",            
              "island","The whole island is just a sandy desert surrounded by sea.",
              "wind","No wind blows here, and the harsh sunshine burns your skin. ",	    
              "sea","The sea rises quite calmly against the shore here",	    
              "scenery","Sand and sea are all you see.",	    
              "sand", "The sand is white here, bleached by the sun.",
              "suns", "Two scorching hot suns, burning your skin as they glare upon you.",
              "sun","Two scorching hot suns, burning your skin as they glare upon you.",
              "tracks","There are no tracks of any kind around this place",
     	      "footprints","There are no footprints of any kind around this place",
              "rays","The rays from the two suns burn you without mercy",
              "water","You are imagining that the water is boiling from the intense heat",
              "globs","It is just your imagination.  It really is just froth from the sea",
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
