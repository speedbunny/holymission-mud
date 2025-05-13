inherit "players/redsexy/jedi/areas/island/inherit";

int _entrance() {
  call_other("/players/mangla/guild/entrance", "???");
  return 1;
}

reset (arg) {     
if (arg) return;    
set_light(1);     

     short_desc="The port town of Carkoon";
     long_desc="The path leads into the an even busier part of town, " +
              "where many creatures come to sit and shelter from the sun " +
              "and talk to one another. There are benches made out of wood " +
              "set in a circular pattern, and sheets draped over the poles "+
              "sticking out of the ground make a canopy of sorts. \n\n";    

dest_dir=({              "/players/redsexy/jedi/areas/island/other/t3.c", "west", 
                         "/players/redsexy/jedi/areas/island/other/t1.c", "south",});
items = ({    
              "creatures","This is a place where they can shelter from the sun",	    
              "path","A well trodden path, firmed by all the passers-by",	    
              "benches","The wooden benches look uncomfortable but provide shelter from the harsh desert sun",
              "stalls","There are no stalls here",	    
              "suns", "Two scorching hot suns, burning your skin as they glare upon you.",
              "sun","Two scorching hot suns, burning your skin as they glare upon you.",
              "sheets","Sheets draped over wooden poles that form a makeshift shelter",
	        "ground","The ground is hard because the sand here is so well trodden",
              "sand","Well trodden sand"
  });

clone_list=({   1, 1, "jawa", "/players/redsexy/jedi/monsters/jawa", 0,
                2, 3, "weequay", "/players/redsexy/jedi/monsters/weequay2", 0          
              });
 
    ::reset();

}

void init() {
   ::init();
   "players/mangla/guild/entrance"->fake_funk();
   add_action("_entrance", "reenter");
   add_action("_sit","sit");
   }

int _sit(string str) {


   if(str!="on bench") return 0;
   write("You rest your legs on one of the benches for a while. \n");
   return 1;


   }




