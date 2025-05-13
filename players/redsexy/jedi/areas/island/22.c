inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;     

set_light(1);     

short_desc="Along the western edge of the island";     

long_desc=    "The atmosphere is unbaerable.  The humidity of the sun and " +
              "the endlessness of the sands.  You realize you could always " +
              "turn back, but at the same time feel like venturing further. " +
              "Who knows what adventures may lie ahead?\n\n";    

dest_dir=({              "/players/redsexy/jedi/areas/island/21.c", "southwest",
                        "/players/redsexy/jedi/areas/island/23.c", "northwest",     });

items = ({            "view","The sea spreads out in front of you, like a blanket of blue",
                      "waves","These waves powerful and dangerous.",
                      "sun","The heat here is humid and smothering.",
                 	    "wind","Harsh and cold, the wind howls across the sea.",
            	    "sea","The sea leaves you spellbound. Never before has nature been so powerful",
            	    "dune sea","The sea leaves you spellbound. Never before has nature been so powerful",
            	    "spray", "The spray tastes salty against your lips, and dampens your hair slightly",
                      "sand","Looking inland you just see miles of sand, but the heat prevents you travelling that way",
            });}

void init() {


   ::init();


   add_action("_search","search");

   }



int _search(string str) {


   if(str!="sand") return 0;
   write("You search as hard as you can but you don't find anything in the sand. \n");
   return 1;


   }
