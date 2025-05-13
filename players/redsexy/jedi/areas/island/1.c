inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return; 

set_light(1);     
short_desc="A jetty on the Sarlacc's Island"; 
long_desc="The view here is spectacular.  Waves lash against the" +
          " jetty, the spray wetting your lips slightly as the wind" +
          " blows to the shore, making you struggle to keep your balance." +
          " The vastness of the Dune Sea spread out in front of you" +              
          " makes you feel small and insignificant.  You realize that" +              
          " even greater adventurers have lost their lives in this sea." +
          " Perhaps it is time to leave before the waves drag you under.\n\n";

dest_dir=({
              "/players/redsexy/jedi/areas/island/2.c", "southeast",
              
          });

items = ({
            "view","The sea spreads out in front of you, like a blanket of blue",
            "waves","These waves powerful and dangerous.",
            "jetty","This old wooden jetty is covered in wet sand.",              
	      "wind","Harsh and cold, the wind howls across the sea, forming clouds of sand ",
	      "sea","The sea leaves you spellbound. Never before has nature been so powerful",
	      "dune sea","The sea leaves you spellbound. Never before has nature been so powerful",
            "spray", "The spray tastes salty against your lips, and dampens your hair slightly",            });


}

void init() {


   ::init();


   add_action("enter","enter"),
   add_action("search","search");

   }


int enter(string str) {


   if(str!="sea") return 0;
   write("You dare not enter this sea, for fear of death! \n");
   return 1;


   }

int search(string str) {


   if(str!="sea") return 0;
   write("You look into the sea from your vantage point, but the power of the waves\n" + " prevents you from searching properly. \n");
   return 1;


   }
