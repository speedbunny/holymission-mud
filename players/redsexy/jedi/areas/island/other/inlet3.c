inherit "room/room";

reset (arg) {     
if (arg) return;
smell="The water smells like old sewers and drainage pipes.";
set_light(1);     

short_desc=   "The slimey waters of the Dune Sea";     

long_desc=    "The slime now covers you completely, and there doesn't seem  " +
              "to be any way out of here.  Your life flashes before your eyes " +
              "as you feel the polluted waste sinking into every orifice and " +
              "pore on your body. \n\n";


items = ({    "waters","This mirky slime isn't exactly what you would call water",            
              "sea","This mirky slime isn't exactly what you would call water",            
              "water","This mirky slime isn't exactly what you would call water",            
              "slime","A horrible putrid slime that covers your body",
              "sludge","Green and mouldy sludge that covers you from head to toe",	    
              "muck","The oily muck covers you as you wade deeper",	    
              "place","This place is awful.",	    
              "pollution","It covers you entirely and there doesn't seem to be any escape",                         
  });

clone_list=({   1, 3, "slime", "/players/redsexy/jedi/monsters/slime", 0,
              });

::reset();


}

void init() {


   ::init();


   add_action("_search","search");
   add_action("_climb","climb");
   }



int _search(string str) {


   if(str!="sand") return 0;
   write("There is no sand here, just horrible slimy water. \n");
   return 1;
}


int _climb(string str) {
   if(str!="out") return 0;
   write("You climb out of the slime. \n");
   this_player()->move_player("this awful slime!#players/redsexy/jedi/areas/island/24");
   return 1;
}


