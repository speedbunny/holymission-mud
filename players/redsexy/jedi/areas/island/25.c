inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;     

set_light(1);     
short_desc="An inlet on the island";     

long_desc=    "You are walking by an inlet on the island. " +
              " Somehow the waves are controlled here, allowing " +
              "anyone who wished to enter the water to do so, " +
              "but the slime and undergrowth seem so unsavoury " +
              "its doubtful anyone would dare.\n\n";    

dest_dir=({              "/players/redsexy/jedi/areas/island/24.c", "south",
                         "/players/redsexy/jedi/areas/island/2.c", "north",     });
items = ({    
              "wind","No wind blows here, and the harsh sunshine burns your skin. ",	    
              "sea","The water from the sea is controlled within this inlet",	    
              "inlet","The water from the sea is controlled within this inlet",
              "scenery","Sand and sea are all you see.",	    
              "sand", "Everywhere you look, just sand",
              "desert","Everywhere you look, just sand",
              "suns", "Two scorching hot suns, burning your skin as they glare upon you.",
              "sun","Two scorching hot suns, burning your skin as they glare upon you.",
              "water","The water looks mirky and polluted",
              "waves","No waves here, just calm but dirty water",
              "undergrowth","Slushy green undergrowth",
              "slime","Smelly slimy slime.  Yuk.",
  });
}

void init() {


   ::init();


   add_action("_enter","enter"),
   add_action("_search","search");

   }


int _enter(string str) {
   if(str!="water") return 0;
   write("You stupidly enter the slimey water. \n");
   this_player()->move_player("stupidly into the slimey water.#players/redsexy/jedi/areas/island/other/inlet1");
   return 1;
   }


int _search(string str) {


   if(str!="sand") return 0;
   write("You search until you realize anything hidden here would have already been \n" + "taken by one of the travelers! \n");
   return 1;


   }
