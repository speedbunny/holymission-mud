inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;    
set_light(1);     

     short_desc="The port town of Carkoon";
     long_desc="You follow the well trodden path into a meeting place " +
              "where Jawa's from all over gather for their annual swap " +
              "meet.  It is here they show off their bartering skills to " +
              "one another, but they are suspicious of any strangers trying "+
              "to join in with the transactions, so you tread with caution. \n\n";    

dest_dir=({              "/players/redsexy/jedi/areas/island/4.c", "south", 
                         "/players/redsexy/jedi/areas/island/3.c", "west",
                         "/players/redsexy/jedi/areas/island/other/t2.c", "north",     });
items = ({    
              "marketplace","Some makeshift stalls are set up around the perimiter of this area ",	    
              "path","A well trodden path, firmed by all the passers-by.",	    
              "place","This is the area where the Jawa's swap meet takes place",
              "stalls","You try to examine the stalls but realise that you'd get killed if you got any closer .",	    
              "suns", "Two scorching hot suns, burning your skin as they glare upon you.",
              "sun","Two scorching hot suns, burning your skin as they glare upon you.",
              
	      
  });

clone_list=({   1, 4, "jawa", "/players/redsexy/jedi/monsters/jawa2", 0,
                          
              });
 
    ::reset();

}

void init() {


   ::init();

   add_action("_enter","enter");
   }

int _enter(string str) {


   if(str!="inlet") return 0;
   write("You cannot enter any of the stalls, for fear of death! \n");
   return 1;


   }




