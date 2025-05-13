#include "lw.h"
#define TO    this_object()
#define TP    this_player()
#define TPN   this_player()->query_name()
#define CLONE clone_object
#define MOVE  move_object
#define TELLR tell_room
inherit "room/room";
int find_treasure();
int find;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="The store room of the Mos Eisley Cantina";
  long_desc="This is obviously the store room of the Mos Eisley cantina. You "+
            "can see many barrels and strange concoctions in flasks and jars adorning "+
            "the floor and the shelves. You are tempted to steal some, but because "+
            "Wunter is such a trusting man you leave "+ 
            "well alone.  What is one creatures amber nectar, you remember, is anothers poison! \n\n  ";

  dest_dir=({"/players/redsexy/jedi/areas/cantina/19","west",
           });

  items=({"bar","This is the Mos Eisley Cantina, and it is packed",
          "creatures","There are so many creatures in here you can barely move",
          "races","Rodians, Quarrens, Wookies, Twi'leks, Whipids - just to name a few!",
          "music","It sounds like a Jizz-wailer band, but you can't place who they are",
          "desert","Forget about it!  RELAX....",
          "barrels","Barrels filled with strange liquids. One even has its lid open",
          "barrel","The lid is open and you can see the green sludge in there is moving",
          "flasks","Flasks filled with weird concoctions",
          "shelves","There is so much junk on the shelves, you cannot even begin to name it all",
          "jars","Jars containing different mixtures",
          "floor","The wooden floor here is rickety",
          "poison","Yes, but how do you make it?",
         });

 
  smell="You can just smell very strong alcohol here.\n";
 
  ::reset();
}

void init() {
  ::init();

  add_action("_pour3", "pour");
  add_action("_pour3", "fill");
  add_action("_pour3", "empty");
  add_action("_search", "search");
}


int _pour3(string str) {
  object item1, item2, item3, flask;

  flask = present("flask", TP);
  if(flask) {
    item1 = present("juri", flask);
    item2 = present("dark", flask);
  }
  else {
    write("Their seems to be something missing from your concoction.\n");
    return 1;
  }

  switch(str) {
    case "liquid into barrel" :
    case "liquid in barrel" :
    case "flask into barrel" :
    case "flask in barrel" :
    case "concoction into barrel" :
    case "concoction in barrel" :
    case "mixture into barrel" :
    case "mixture in barrel" :
    case "barrel with flask" :
    case "barrel with liquid" :
    case "barrel with mixture" :
    case "barrel with concoction" :

      if(!flask) {
        write("Which flask would that be?\n");
        return 1;
      }
      write("You empty the flask into the barrel.\n");
      say(TPN + " empties their flask into the barrel.\n");
      if(item1 && item2) {
        destruct(item1);
        destruct(item2);
        item3=clone_object("/players/redsexy/jedi/objects/poison.c");
        transfer(item3,this_object());
        TELLR(TO, "The concoction bubbles and the barrel becomes smaller!\n");
      }
      else
        write("Shouldn't something have happened?\n");
      return 1;
    case "flask" :
      notify_fail("Pour flask where?\n");
      return 0;
    default :
      notify_fail("Pour what?\n");
      return 0;
  }
}

int _search(string str) {

   if(str=="shelves" || str =="shelf") 
      say(this_player()->query_name()+" searches the shelves.\n");
      find_treasure();
      return 1;
    }
   

find_treasure() {
object jar;
      
  if(present("jar",this_player())) {
    write("You search and find nothing but dust...\n");
    return;
    find=1;
  }
  
  if(find) {
    write("You search the shelves but there is nothing there...\n");
    return;
  }

  write("You search the shelves and find a jar of some sorts!\n");
  jar=clone_object("players/redsexy/jedi/objects/jar");
  transfer(jar,this_player());
  find=1;
  return;
}




