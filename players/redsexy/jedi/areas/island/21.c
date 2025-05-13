inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {
if (arg) return;     

set_light(1);     

short_desc="Continuing along the west coast of Carkoon.";

long_desc="You rest a while to gaze out at the sea, admire its power " +
              "and beauty.  The sand is too hot to lie on though and it is " +
              "too uncomfortable to rest anywhere for long, with the evil " +
              "treacherous suns beating down your neck.\n\n";    

dest_dir=({              "/players/redsexy/jedi/areas/island/20.c", "southeast",
                         "/players/redsexy/jedi/areas/island/22.c", "northeast",     });

items = ({  "view","The sea spreads out in front of you, like a blanket of blue",
            "waves","These waves powerful and dangerous.",
            "sand","The sand is white hot, and too uncomoftable to rest on",
            "wind","Harsh and cold, the wind howls across the sea.",
	      "sea","The sea leaves you spellbound. Never before has nature been so powerful",
            "dune sea","The sea leaves you spellbound. Never before has nature been so powerful",
            "spray", "The spray tastes salty against your lips, and dampens your hair slightly",
            "suns","There are two suns in the sky, endlessly emitting rays",
            "sun","There are two suns in the sky, endlessly emitting rays",            });

}

void init() {


   ::init();


   add_action("_search","search");

   }



int _search(string str) {


   if(str!="sand") return 0;
   write("You find nothing in the sand around here. \n");
   return 1;


   }
