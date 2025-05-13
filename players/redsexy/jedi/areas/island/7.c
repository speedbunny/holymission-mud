inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) { 
    if (arg) return; 

    set_light(1); 
    short_desc="The desert coastline of the Sarlacc's island."; 
    long_desc="Still following the coastline, life seems very scarce around"+
              " here, the huts are all abandoned and there are few footprints"+
              " in the sand.  All you can see are desert and sea, sea and desert"+
              " as you venture on through this tedious land.\n\n";

    dest_dir=({
              "/players/redsexy/jedi/areas/island/36.c", "south",
              "/players/redsexy/jedi/areas/island/8.c", "southeast",
              "/players/redsexy/jedi/areas/island/6.c", "southwest",
              
     });

items = ({
            "view","The sea spreads out in front of you, like a blanket of blue",
            "waves","These waves powerful and dangerous.",
            "sand","A blanket of sand as far as the eye can see.",              
            "wind","The wind is blustery here",
	    "sea","The sea leaves you spellbound. Never before has nature been so powerful",
	    "dune sea","The sea leaves you spellbound. Never before has nature been so powerful",
	    "desert", "Just miles and miles of sand",
            "footprints","There are hardly any footprints here",
            });


}

void init() {

   ::init();

   add_action("search","search");

   }



int search(string str) {

   if(str!="sand") return 0;

   write("You dig and burrow through the sand but find nothing here. \n");


   return 1;

   }

