inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;    
set_light(1);     

     short_desc="An inlet on the island";
     long_desc="The inlet finishes here, and you can see the sea " +
              "in its full glory again.  A few tracks " +
              "lead inland from here, and you wonder what lies " +
              "beyond this coast line. \n\n";    

dest_dir=({              "/players/redsexy/jedi/areas/island/23.c", "southwest", 
                         "/players/redsexy/jedi/areas/island/26.c", "southeast",
                         "/players/redsexy/jedi/areas/island/25.c", "north",     });
items = ({    
              "wind","No wind blows here, and the harsh sunshine burns your skin. ",	    
              "sea","You can see the sea beating against the shore here",	    
              "inlet","The water from the inlet comes to an end here",
              "scenery","Sand and sea are all you see.",	    
              "sand", "Everywhere you look, just sand",
              "desert","Everywhere you look, just sand",
              "suns", "Two scorching hot suns, burning your skin as they glare upon you.",
              "sun","Two scorching hot suns, burning your skin as they glare upon you.",
              "water","The water looks mirky and polluted",
              "waves","No waves here, just calm but dirty water",
              "tracks","The tracks lead southeast towards the mainland",
	      "coast","The coast of this island, where the sand and sea meet",              
  });
}

void init() {


   ::init();


   add_action("_search","search");
   add_action("_enter","enter");
   }

int _enter(string str) {


   if(str!="inlet") return 0;
   write("You cannot enter the inlet from here! \n");
   return 1;


   }



int _search(string str) {


   if(str!="sand") return 0;
   write("The sand is too hot to search so you give up entirely! \n");
   return 1;


   }
