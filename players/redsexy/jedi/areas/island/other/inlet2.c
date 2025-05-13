inherit "room/room";

reset (arg) {     
if (arg) return;
smell="The water smells like old sewers and drainage pipes.";
set_light(1);     

short_desc=   "The slimey waters of the Dune Sea";     

long_desc=    "Even deeper into this controlled area of sea now, the  " +
              "oily, smelly slime reaches upto your neck.  You are choking " +
              "through the stench of this foul area of pollution and " +
              "even the harsh sands of the desert seem better than this.\n\n";


items = ({    "waters","This mirky slime isn't exactly what you would call water",            
              "sea","This mirky slime isn't exactly what you would call water",            
              "water","This mirky slime isn't exactly what you would call water",            
              "slime","A horrible putrid slime that covers your body",
              "sludge","Green and mouldy sludge that covers you from head to toe",	    
              "muck","The oily muck covers you as you wade deeper",	    
              "place","This place is awful.",	    
              "pollution","Maybe you could try wading in various directions to get out of here?",                         
  });
clone_list=({   1, 3, "oil", "/players/redsexy/jedi/monsters/oil", 0,
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
   if(str!="north") return 0;
   write("You try to wade north but just sink in deeper! \n");
   this_player()->move_player("Deeper into the slime!#players/redsexy/jedi/areas/island/other/inlet3");
   return 1;
}

int _climb(string str) {
   if(str!="out") return 0;
   write("You climb out of the slime. \n");
   this_player()->move_player("this awful slime!#players/redsexy/jedi/areas/island/24");
   return 1;
}


