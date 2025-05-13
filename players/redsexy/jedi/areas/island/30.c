inherit "players/redsexy/jedi/areas/island/inherit";
 
reset (arg) {     
if (arg) return;     

set_light(1);      

short_desc="A hunting ground on the island";     

long_desc="You are now walking across the vast plains of sand that spread " +
              "across the island.  The scenery here is not even worth a mention. " +
              "Just sand, everywhere, and two menacing hot suns glaring down evilly " +
              "from the sky.  You sense danger here, there are many tracks and signs " +
              "of a struggle.  It is obvious that sand people and bounty hunters alike " +
              "scout this area for the elusive Krayt Dragon, a legendary creature of " +
              "strength and beauty to rival the most determined of opponents.\n\n";    

dest_dir=({               "/players/redsexy/jedi/areas/island/14.c", "southeast",
                          "/players/redsexy/jedi/areas/island/31.c", "southwest",
                          "/players/redsexy/jedi/areas/island/39.c", "east",
                          "/players/redsexy/jedi/areas/island/29.c", "northwest",     });

items = ({    "view","Sand spreads out in front of you, behind you, everywhere.",            
              "plains","Sand spreads out in front of you, behind you, everywhere.",            
              "island","The whole island is just a sandy desert surrounded by sea.",
              "wind","No wind blows here, and the harsh sunshine burns your skin. ",	    
              "sea","You cannot see the sea from here",	    
              "scenery","Sand spreads out in front of you, behind you, everywhere.",	    
              "sand", "The sand is like cinders, burning your poor feet.",
              "suns", "Two menacing hot suns, burning your skin as they glare upon you.",
              "sun","Two menacing hot suns, burning your skin as they glare upon you.",
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
   write("You furrow through the sand methodically,\n" + "but there is no hidden treasure here. \n");
   return 1;


   }
