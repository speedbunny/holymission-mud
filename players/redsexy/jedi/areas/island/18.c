inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     

if (arg) return;     
set_light(1);     

short_desc="The jagged west coast of the Sarlacc's island."; 
long_desc=    "You feel tired as you continue along the coast " +
              "of this strange desert island.  Your feet ache from " +
              "the distance you have covered, and the repetitive sun " +
              "and sand make you feel dizzy.\n\n";    

dest_dir=({              "/players/redsexy/jedi/areas/island/17.c", "south",
                         "/players/redsexy/jedi/areas/island/19.c", "northwest",     });

items = ({    "view","Sand spreads out in front of you, behind you, everywhere.",            
              "plains","Sand spreads out in front of you, behind you, everywhere.",            
              "island","The whole island is just a sandy desert surrounded by sea.",
              "wind","No wind blows here, and the harsh sunshine burns your skin. ",	    
              "sea","The sea rises quite calmly against the shore here",	    
              "scenery","Sand and sea are all you see.",	    
              "sand", "Everywhere you look, just sand",
              "desert","Everywhere you look, just sand",
              "suns", "Two scorching hot suns, burning your skin as they glare upon you.",
              "sun","Two scorching hot suns, burning your skin as they glare upon you.",
              "tracks","There are no tracks of any kind around this place",
              "footprints","There are no footprints of any kind around this place",
              "rays","The rays from the two suns burn you without mercy",

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
