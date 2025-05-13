inherit "room/room";

#include "hobbe_defs.h"
#include "/players/kryll/rooms/room_defs.h"

// prototypes
static private void init_counter();

static private int fcounter;
static private status is_empty, has_found;

static private void init_counter() {
  fcounter = 10 + random(21);
  is_empty = 0;
  has_found = 0;
}

void reset(int arg){
  init_counter();

  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "Inside the watermill";
  long_desc =
    "You're inside the watermill. The walls are made of oak and "+
    "beautiful pictures covers the walls. To your right you notice "+
    "a giant millstone and right before you stand several large "+
    "sacks filled with flour. There are also stairs leading upstairs "+
    "and downstairs.\n";

  items = ({
    "millstone","A really heavy millstone",
    "stone","A really heavy millstone",
    "floor","You see a floor made of stone",
    "walls","They are made of oak",
    "wall","They are made of oak",
    "pictures","You see the daughter of Hobbe smiling friendlily",
    "sacks","There are several sacks around the room filled with flour",
    "stairs","They lead upstairs and downstairs"
  });

  dest_dir = ({
    HOBBE_DIR + "upstairs", "up",
    HOBBE_DIR + "cellar", "down",
    HOBBE_DIR + "path2", "out",
  });
}

void init(){
  ::init();
  add_action("_push", "push");
  add_action("_push", "move");
}

status ser(string str) {

}

search(str) {
  int tmp;
  object ob;

  if(fcounter < 1)
    is_empty = 1;

  switch(str) {
    case "flour" :
      if(present("flour", TO)) {
        writelw("You start sifting through the flour on the floor, "+
                "but you don't find anything.\n");
        say(TP->NAME + " starts sifting through the flour on the floor.\n");
        return 1;
      }
      break;
    case "chest" :
      if(is_empty) {
        writelw("You search the empty chest and discover ... "+
                "absolutely NOTHING!\n");
        say(TP->NAME + " searches the chest.\n");
        return 1;
      }
      if(!random(fcounter/2) && !has_found) {
        fcounter--;
        has_found = 1;
        ob = clone_object(HOBBE_DIR + "hammer");
        if(!transfer(ob, TP)) {
          transfer(ob, TO);
          writelw("While searching through the flour in the chest, "+
                  "you come across a hammer, but it slips through "+
                  "your fingers and falls to the floor.\n");
          say(lw(TP->NAME + " searches through the chest, finds a "+
                 "hammer and drops it.\n"));
          ob = clone_object(HOBBE_DIR + "flour");
          transfer(ob, TO);
          return 1;
        }
        writelw("While searching through the flour in the chest, "+
                "you come across a hammer and decide to keep it.\n");
        say(lw(TP->NAME + " searches through the chest, finds a "+
               "hammer and puts it away somewhere.\n"));
        ob = clone_object(HOBBE_DIR + "flour");
        transfer(ob, TO);
        return 1;
      }
      fcounter--;
      writelw("You digging through the floor, you spill some on the "+
              "flour.\n");
      say(TP->NAME + " makes a mess searching the chest.\n");
      ob = clone_object(HOBBE_DIR + "flour");
      transfer(ob, TO);
      return 1;
    default :
      notify_fail("Search what?\n");
      return 0;
  }
}

#if 0
  if (arg=="chest") {
    if(fcounter >= 10) {
 	write( "You find some flour.\n" +
               "But as you try to get it, it slips through your fingers.\n" );
         return 1;
      }
    else if (fcounter != 5) {
         write("You find some flour.\n");
         say(this_player()->query_name()+" searches the chest.\n");
         ob=clone_object(HOBBE_DIR + "flour");
         if (transfer(ob,this_player())) {
            write("But you can't carry that much.\n");
            destruct(ob);
            return 1;
         }
    fcounter++;
    return 1;
      }
      else {
         arg = "flour";
         fcounter++;
      }
   }
   
  if(arg=="flour"){
    if(counter<1){
         write("You find a hammer.\n");
         say(this_player()->query_name()+" searches the chest.\n");
         ob=clone_object(HOBBE_DIR + "hammer");
         if (transfer(ob,this_player())) {
            write("But you can't carry that much.\n");
            destruct(ob);
            return 1;
         }
            
    counter = 1;
    return 1;
      }
   }      
   write("You search and search, but find nothing.\n");
   say(this_player()->query_name()+" searches around.\n");
   return 1;
}
#endif

status _close(string str){
  if(!str || str!="chest") {
    notify_fail("Close what?\n");
    return 0;
  }
      
  writelw("You try to close the heavy chest, but the top has already "+
          "rusted open.\n");
  say(TP->NAME + " shows " + TP->POS + " weakness.\n");
  return 1;
}

status _open(string str){
  if(!str || str!="chest") {
    notify_fail("Open what?\n");
    return 0;
  }
  write("The chest is already open!\n");
  say(TP->NAME + " shows how braindamaged " + TP->query_pronoun() + " is!\n");
  return 1;
}

status _push(string str) {
  switch(str) {
    case "millstone" :
    case "stone" :
      write("The stone is much too heavy to move !\n");
      say(TP->NAME + " tries to move the millstone, but fails.\n");
      return 1;
    default :
      notify_fail("Move what ?\n"); 
      return 0;
  }
}
