inherit "room/room"; 

reset (arg) { 
    if (arg) return; 
    smell="You ever wanted to know what fear smells like?\n" +
          "The stench of the Sarlacc, an old leathery, sweaty smell," +
          "makes you tremble to the bone.";

    set_light(1); 
short_desc="On the edge on the Sarlacc's pit, on the Island of Carkoon"; 
    long_desc="You have stumbled upon the legendary Pit of Carkoon" +
              " where the fabled Sarlacc lives.  You have heard much about " +
              "this creature, but can only make out a gigantic mouth and " +
              "tongue munching at the surface of this giant landslide of a " +
              "dwelling place.  You would have to be very brave to enter " +
              "here and highly skilled to leave alive, so you excersize " +
              "caution as you pad around the area surrounding this hole.\n\n";
              

    dest_dir=({
    
              "/players/redsexy/jedi/areas/island/10.c", "northeast",
     });

items = ({
            "pit","This is the Great Pit of Carkoon where the Sarlacc lives",
            "sarlacc","The sarlacc is giantic, and his mouth and teeth alone are visible",
            "creature","The creature is the much fabled Sarlacc",              
     	      "hole","The hole is giantic, and the sarlacc lives down there",
            "sand","You're worrying about sand when you face the mighty sarlacc??!!"
            });

}

void init() {


   ::init();


   add_action("_enter","enter"),
   add_action("_search","search");
   add_action("_kill","kill");
   add_action("_jump","jump");
   add_action("_exa","examine");
   }


int _enter(string str) {
   if(str!="pit") return 0;
   write("You decide to enter the Great Pit of Carkoon. \n");
   this_player()->move_player("into the Great Pit of Carkoon bravely.#players/redsexy/jedi/areas/island/deeppit.c");
   return 1;
   }


int _search(string str) {


   if(str!="sand") return 0;
   write("Search?! In this dangerous place?! \n");
   return 1;


   }

int _exa(string str) {


   if(str!="great pit of carkoon") return 0;
   write("You think you could jump into this pit!\n");
   return 1;


   }

int _kill(string str) {


   if(str!="sarlacc") return 0;
   write("You cannot kill the Sarlacc from here. \n");
   return 1;


   }

int _jump(string str) {


   if(str!="into pit") return 0;
   write("You jump bravely into the Great Pit of Carkoon. \n");
   this_player()->move_player("into the Great Pit of Carkoon bravely.#players/redsexy/jedi/areas/island/deeppit.c");
   return 1;
   }
