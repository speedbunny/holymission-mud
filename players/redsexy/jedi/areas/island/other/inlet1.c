inherit "room/room";

reset (arg) {     
if (arg) return;
smell="The water smells like old sewers and drainage pipes.";

set_light(1);     

short_desc=   "The slimey waters of the Dune Sea";     

long_desc=    "You have entered the putrid waters of the Dune Sea.  " +
              "This sludge is more like a polluted slime than water " +
              "and you gasp for breath as you slowly begin to drown in  " +
              "the muck.  The vile smell here fills your lungs and your " +
              "mouth, and it seems there is no escape from this awful place.\n\n";


items = ({    "waters","This mirky slime isn't exactly what you would call water",            
              "water","This mirky slime isn't exactly what you would call water",            
              "slime","A horrible putrid slime that covers your body",
              "sludge","Green and mouldy sludge that covers you from head to toe",	    
              "muck","The oily muck covers you as you wade deeper",	    
              "place","This place is awful.  You could try to wade out of here, maybe?",	    
                         
  });

clone_list=({   1, 3, "mould", "/players/redsexy/jedi/monsters/mould", 0,
              });

::reset();


}

void init() {


   ::init();


   add_action("_search","search");
   add_action("_wade","wade");
   add_action("_climb","climb");
   }



int _search(string str) {


   if(str!="sand") return 0;
   write("There is no sand here, just horrible slimy water. \n");
   return 1;
}

int _wade(string str) {
   if(str!="east") 
   return 0;
   write("You try to wade east but just sink in deeper!\n");
   this_player()->move_player("Deeper into the slime!#players/redsexy/jedi/areas/island/other/inlet2");
   return 1;
}

int _climb(string str) {
   if(str!="out") return 0;
   write("You climb out of the slime. \n");
   this_player()->move_player("this awful slime!#players/redsexy/jedi/areas/island/24");
   return 1;
}


