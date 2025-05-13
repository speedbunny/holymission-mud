inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;     

set_light(1);     
short_desc="The easternmost edge of the Sarlacc's island.";
long_desc="You have followed the coast to the eastern most" +
              " point on the island.  The sea here looks as " +
              " threatening as ever, but just barely on the " +
              " horizon you can make out some kind of grand" +
              " structure.\n\n";    

dest_dir=({              "/players/redsexy/jedi/areas/island/12.c", "southwest",              
                         "/players/redsexy/jedi/areas/island/10.c", "northwest",     
         });

items = ({  "view","The sea spreads out in front of you, like a blanket of blue",            
            "waves","These waves powerful and dangerous.",       
            "horizon","You can see a building on the land beyond the sea",
            "building","The building seems to be some kind of palace",
            "palace","It looks magnificent from here, you wonder how to get there",
            "coast","You stand on the easternmost edge of the coast",               	    
            "wind","Harsh and cold, the wind howls across the sea.",	    
            "sea","The sea leaves you spellbound. Never before has nature been so powerful",
            "dune sea","The sea leaves you spellbound. Never before has nature been so powerful",
	      "spray", "The spray tastes salty against your lips, and dampens your hair slightly",            });

}

void init() {

   ::init();
   add_action("_swim","swim"),
   add_action("_search","search");

   }



int _search(string str) {

   if(str!="sand") return 0;

   write("You scour the sand all over and find nothing. \n");

   return 1;

   }

int _swim() {

   write("You cannot swim to the palace from here, the sea is too dangerous. \n");

   return 1;

   }
