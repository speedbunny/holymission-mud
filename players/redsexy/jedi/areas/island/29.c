inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;     

set_light(1);       

short_desc="A hunting ground on the island";     

long_desc="You are now walking across the vast plains of sand that spread " +
              "across the island.  The scenery here is not even worth a mention. " +
              "Just sand, everywhere, and two firey hot suns glaring down evilly " +
              "from the sky.  You sense danger here, there are many tracks and signs " +
              "of a struggle.  It is obvious that sand people and bounty hunters alike " +
              "scout this area for the elusive Krayt Dragon, a legendary creature of " +
              "strength and beauty to rival the most determined of opponents.\n\n";    

dest_dir=({               "/players/redsexy/jedi/areas/island/30.c", "southeast",
                          "/players/redsexy/jedi/areas/island/28.c", "southwest",
                          "/players/redsexy/jedi/areas/island/27.c", "west",
                          "/players/redsexy/jedi/areas/island/38.c", "northeast",     });

items = ({    "view","Sand spreads out in front of you, behind you, everywhere.",            
              "plains","Sand spreads out in front of you, behind you, everywhere.",            
              "island","The whole island is just a sandy desert surrounded by sea.",
              "wind","No wind blows here, and the harsh sunshine burns your skin. ",	    
              "sea","You cannot see the sea from here",	    
              "scenery","Sand spreads out in front of you, behind you, everywhere.",	    
              "sand", "The sand is like cinders, burning your poor feet.",
              "suns", "Two firey hot suns, burning your skin as they glare upon you.",
              "sun","Two firey hot suns, burning your skin as they glare upon you.",
	      "tracks","Many footprints and tracks make the sand hard underfoot ",
	      "footprints","Many footprints and tracks make the sand hard underfoot ",
              "sand people","There are no sandpeople here",
              "people","There is no life of any kind to be seen around here",
              "signs","Signs of a massive fight, blood stains and bones lay scattered",
              "bones","Decomposing bones and skin make you feel sick to the stomach",
              "bloodstains","The sand has brownish red patches in places which look like blood",
              "dragon","There is no sign of the Krayt Dragon here"             });
clone_list=({   1, 5, "sanperson", "/players/redsexy/jedi/monsters/sandperson", 0
         
              });
 
    ::reset();


}


void init() {


   ::init();


   add_action("_search","search");

   }



int _search(string str) {


   if(str!="sand") return 0;
   write("Searching through the sand reveals nothing but more sand. \n");
   return 1;


   }
