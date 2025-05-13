inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;     

set_light(1);     

short_desc="The jagged west coast of a desert island";     

long_desc="The coastline here is more jagged as you follow " +
              "it around.  Little splinters of broken stones mix " +
              "with the sand making it uncomfortable underfoot, but " +
              "you contine to explore regardless.\n\n";    

dest_dir=({              "/players/redsexy/jedi/areas/island/18.c", "southeast",
                         "/players/redsexy/jedi/areas/island/20.c", "north",     });

items = ({    "view","Sand spreads out in front of you, behind you, everywhere.",            
              "plains","Sand spreads out in front of you, behind you, everywhere.",            
              "island","The whole island is just a sandy desert surrounded by sea.",
              "coast","The coastline which you are following",	    
              "coastline","The coastline which you are following",
              "sea","The sea rises quite calmly against the shore here",	    
              "scenery","Sand and sea are all you see.",	    
              "sand", "Everywhere you look, just sand",
              "desert","Everywhere you look, just sand",
              "suns", "Two scorching hot suns, burning your skin as they glare upon you.",
              "sun","Two scorching hot suns, burning your skin as they glare upon you.",
              "tracks","There are no tracks of any kind around this place",
              "footprints","There are no footprints of any kind around this place",
              "rays","The rays from the two suns burn you without mercy",
              "splinters","Little splintered stones make this terrain uncomfortable to walk on",
              "stones","Little splintered stones make this terrain uncomfortable to walk on",

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
