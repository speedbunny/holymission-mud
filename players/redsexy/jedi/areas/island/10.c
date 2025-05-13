inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;     

set_light(1);     
short_desc="A dangerous place on the coastline of Carkoon";     
long_desc="You sense great danger nearby as you follow" +
          " the coast around the island.  Attuned to the" +
          " waves of the sea and all the menace they hold" +
          " you just know that something far more sinister" +
          " lurks just around the corner.\n\n";    

dest_dir=({         "/players/redsexy/jedi/areas/island/11.c", "southeast",              
                    "/players/redsexy/jedi/areas/island/pit.c", "southwest",              
                    "/players/redsexy/jedi/areas/island/9.c", "north",     
         });

items = ({            "view","The sea spreads out in front of you, like a blanket of blue",            
                      "waves","These waves powerful and dangerous.",	    
                      "wind","Harsh and cold, the wind howls across the sea.",	    
                      "island","This island is just one sandy hell hole.",
                      "something","You don't know what quite yet, but there is some bad waiting around here",
                      "sea","The sea leaves you spellbound. Never before has nature been so powerful",	    
                      "dune sea","The sea leaves you spellbound. Never before has nature been so powerful",	    
                      "spray", "The spray tastes salty against your lips, and dampens your hair slightly",
                      "danger","Isn't this the island where the legendary Sarlacc lives?",
                      "coast","The smooth coastline continues to the southeast",            });

}

void init() {

   ::init();

   add_action("search","search");

   }



int search(string str) {

   if(str!="sand") return 0;

   write("With danger lurking so near, the last thing on your mind is searching the sand!! \n");

   return 1;

   }
