inherit "players/redsexy/jedi/areas/island/inherit";

void reset(int arg)   {
    if (arg) return; 

    set_light(1); 
    short_desc="A port town on the island"; 
    long_desc="A well defined path runs through this port town"+
              " and it looks as though many travelers have passed"+
              " this way, firming the sand of the desert underfoot."+
              "  You find it hard to believe anything could survive"+
              " in this heat, yet there are small huts dotted about"+
              " this area, and creatures of many races scurry around"+
              " getting on with their everyday business.  You think"+
              " from the hustle around here, this may be a trading"+
              " post.\n \n";  

    dest_dir=({
              "/players/redsexy/jedi/areas/island/34.c", "south",
              "/players/redsexy/jedi/areas/island/5.c", "southeast",
              "/players/redsexy/jedi/areas/island/3.c", "northwest",
              "/players/redsexy/jedi/areas/island/other/t1.c", "north",
              
     });

items = ({
            "path","A well trodden path, defined by the footprints of many travelers.",
            "port","No boats float in the docking bay of this deserted port.",
            "waves","These waves powerful and dangerous.",
            "travelers","Footprints in the sand show many travelers have ventured here.",             
	    "footprints","Footprints in the sand show many travelers have ventured here.",             
	    "sea","The sea leaves you spellbound. Never before has nature been so powerful",
	    "dune sea","The sea leaves you spellbound. Never before has nature been so powerful",
	    "sand","The sand is well trodden and firmer here.",
            "desert","The sand is well trodden and firmer here.",
            "huts","There are many wooden huts dotted around, they look like shops.",
            "shops","One hut stands out in particular, perhaps you should enter it?",
            "hut", "This hut looks like it is open for trade, why not go inside?",
            "creatures", "There are many creatures here causing a commotion!",
            "hustle", "There are some creatures here causing a commotion!",
            });

clone_list=({   1, 5, "jawa", "/players/redsexy/jedi/monsters/jawa2", 0,
                2, 2, "sandperson", "/players/redsexy/jedi/monsters/sandperson2", 0,
                3, 2, "weequay", "/players/redsexy/jedi/monsters/weequay2", 0          
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
   write("You decide to enter one of the stores. \n");
   this_player()->move_player("into the small hut.#players/redsexy/jedi/areas/island/other/hut");
   return 1;
   }


int _search(string str) {


   if(str!="sand") return 0;
   write("You search until you realise anything hidden here would have already been \n" + "taken by one of the travelers! \n");
   return 1;


   }
