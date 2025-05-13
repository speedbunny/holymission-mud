inherit "room/room"; 

reset (arg) { 
    if (arg) return; 

    set_light(1); 
short_desc="An inhabitant's hut on the Island of Carkoon"; 
    long_desc="This hut is obviously the home of one of the island's creatures.  " +
              "Very plain and simply decorated, it seems that the only possesions " +
              "this poor soul owns are the blankets that lie on the floor.\n\n ";

items = ({    "blankets","Some tattered old blankets lie on the floor",            
              "plain","Nothing to see here.",            
              "decoration","The creature has put up a picture of his family.",
              "picture","A picture of a Weequay family",	    
              "walls","All that adorns the walls here is a picture",	    
              "floor","The floor is very dusty",	    
            });

clone_list=({   1, 1, "weequay", "/players/redsexy/jedi/monsters/weequay", 0
  
              });
::reset();

              }
void init() {
   ::init();
   add_action("_leave","leave");
   add_action("_search","search");
   }

int _leave(string str) {
   if(str!="hut") return 0;
   write("You decide to leave this empty place!. \n");
   this_player()->move_player("out of the small hut.#players/redsexy/jedi/areas/island/4");
   return 1;
   }

int _search(string str) {
   if (str!="blankets") return 0;
   write ("You search the creature's blankets but find nothing! \n");
   return 1;
   }
