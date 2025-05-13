inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {
if (arg) return;     

set_light(1);     
short_desc="Following a path on the island of Carkoon";     
long_desc="You are following a well defined path running to the" +  
          " east side of the port, the sand firm underfoot from" +
          " the constant passing of travelers and inhabitants in" +              
          " this area.  The heat is sweltering as you pass through" +              
          " here and you feel a certain sympathy for the creatures" +              
          " that inhabit the huts which are built around the path." + 
          "  This seems to be a residential area, but quite how anyone" +              
          " can survive here is a mystery\n\n";    

dest_dir=({              "/players/redsexy/jedi/areas/island/5.c", "southwest",              
                         "/players/redsexy/jedi/areas/island/7.c", "northeast",                   
});

items = ({            "path","A well trodden path, defined by the footprints of many travelers.",            
                      "port","No boats float in the docking bay of this deserted port.",            
                      "waves","These waves powerful and dangerous.",            
                      "travelers","Footprints in the sand show many travelers have ventured here.",             	    
                      "footprints","Footprints in the sand show many travelers have ventured here.",             	    
                      "sea","The sea leaves you spellbound. Never before has nature been so powerful",
            	    "dune sea","The sea leaves you spellbound. Never before has nature been so powerful",
             	    "sand","The sand is well trodden and firmer here.",            
                      "desert","The sand is well trodden and firmer here.",            
                      "huts","There are many wooden huts dotted around, one stands out in particular.",            
                      "hut", "This hut looks like the owner has left the door open, you could maybe go inside?",            });

clone_list=({   1, 3, "jawa", "/players/redsexy/jedi/monsters/jawa", 0,
                2, 1, "weequay", "/players/redsexy/jedi/monsters/weequay", 0          
                              });
 
    ::reset();

}

void init() {   

::init();   

add_action("_search","search"),
add_action("_enter","enter");   

}

int _enter(string str) {   

   if(str!="hut") return 0;   

write("You decide to enter the open hut. \n");   

this_player()->move_player("into the small hut.#players/redsexy/jedi/areas/island/other/hut2");   

return 1;   }

int _search(string str) {


   if(str!="sand") return 0;
   write("You search until you realize anything hidden here would have already been \n" + "taken by one of the travelers! \n");
   return 1;


   }

