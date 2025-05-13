inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;     

set_light(1);     

short_desc="The edge of a port town on the island";     
long_desc="You are on the edge of the island's port-town, and there is little life"+
          " to be seen. A few huts are scattered far apart from each other, and"+	      
          " over the plains of sand you can just barely make out a path to the southeast."+              
          "  The sea lashes against the coast line with a thunderous roar.  \n\n";    

dest_dir=({              "/players/redsexy/jedi/areas/island/2.c", "southwest",              
                         "/players/redsexy/jedi/areas/island/4.c", "southeast",
                         "/players/redsexy/jedi/areas/island/other/t1.c", "east",
                         "/players/redsexy/jedi/areas/island/other/t3.c", "north",
				
                   });

items = ({  "huts","Little huts where the poor unfortunates who were banished here live",            
            "hut","A little hut where one of the poor unfortunates who were banished here lives",            
            "waves","These waves are powerful and dangerous.",	    
            "wind","Harsh and cold, the wind howls across the sea.",	    
            "sea","The sea leaves you spellbound. Never before has nature been so powerful",
            "dune sea","The sea leaves you spellbound. Never before has nature been so powerful",
	      "path", "What was once a well worn path turns into sandy plains",            
            "coast line", "No sign of rocks or any kind of life, the dessert sands are the only coast line",            
            "town", "The remains of scattered huts on the outskirts of a town",            
            "sand","The sand is less firm underfoot as the path dwindles out",
            "life","There is no life here",
            "coast","The coast of this island"            });



clone_list=({   1, 3, "jawa", "/players/redsexy/jedi/monsters/jawa", 0,
                          
              });
 
    ::reset();
 
}

void init() {

   ::init();

   add_action("_enter","enter"),
   add_action("_search","search");

   }



int _enter(string str) {
   if(str!="hut") return 0;
   write("You cannot enter any of the huts here. \n");
   return 1;

   }

int _search(string str) {


   if(str!="sand") return 0;
   write("You search the sand thoroughly but there is nothing here. \n");
   return 1;


   }
