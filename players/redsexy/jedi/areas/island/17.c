inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) { 
    if (arg) return; 

    set_light(1); 
short_desc="The trecherous southern coast of Carkoon."; 
    long_desc="You have reached the southern most tip of the island, " +
              "the plains of sand virtually untouched here, the sea " +
              "fierce and menacing.  Everything looks the same as " +
              "far as the eye can see.  You don't think you are lost " +
              "but at the same time, you are not sure you can find the " +
              "way home...\n\n"; 

    dest_dir=({

              "/players/redsexy/jedi/areas/island/18.c", "north",
              "/players/redsexy/jedi/areas/island/16.c", "northeast",
     });

items = ({
            "view","The sea spreads out in front of you, like a blanket of blue",
            "waves","These waves are powerful and dangerous.",
	    "wind","Harsh and cold, the wind howls across the sea.",
	    "sea","The sea leaves you spellbound. Never before has nature been so powerful",
	    "dune sea","The sea leaves you spellbound. Never before has nature been so powerful",
	    "island", "The island looks the same all over.  Sand, sand and even more sand",
            "sand", "The harsh warm sand of the desert underfoot",
            });


}

void init() {


   ::init();


   add_action("_search","search");

   }



int _search(string str) {


   if(str!="sand") return 0;
   write("You dig around for a little while, but don't find a bean.  \n");
   return 1;


   }
