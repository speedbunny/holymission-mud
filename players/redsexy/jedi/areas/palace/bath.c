inherit "/room/room";
#include "/players/whisky/houses/swifto/defs.h"
int find_treasure();
int find;

void reset(int flag)
{
     if (flag == 0)
     {
         set_light(1);
        short_desc = "In a big wooden bath-tub";
         long_desc = BS(
        "You are inside a big marble bathtub. It's full of "+
         "pleasant warm water. The water is perfumed and smells "+
         "like blossom."); 
        
        items =
        ({
         "water","The warm water smells like blossom",
         "tub","You are inside of the big tub",
        });

         dest_dir =
         ({
           "/players/redsexy/jedi/areas/palace/34","out",
         }); 
     }
   }

void init()
{
    ::init();
    this_player()->set_smell(this_player()->query_pronoun()+
                   " smells freshly scented and squeaky clean."); 
    add_action("_search","search");

}

int _search(string str) {
  object ob;

  switch(str) {
    case "water" :
    case "in water" :
    case "bath" : 
    case "in bath" :
        write("You immerse yourself in the bubbles of the bath...\n");
               find_treasure();
               return 1;
    default :
      notify_fail("Where do you want to search?\n");
      return 0;
  }
}


find_treasure() {
    object ob;
      
  if(present("jabba_throne",this_player())) {
    write("But there's nothing there.\n");
    return;
    find=1;
}
  
  if(find) {
    write("And splutter a little as you resurface empty handed.\n");
    return;
}
    write ("And find a key hidden beneath the bubbles!\n");
        ob=clone_object("/players/redsexy/jedi/objects/jabba_throne");
        transfer(ob,this_player());
        find=1;
        return 1;
}


