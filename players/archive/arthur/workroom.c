#include "room.h"
#include "/players/arthur/defs/ardefs.h"
int amm;
object bird;
FOUR_EXIT("room/church","church",
          "players/nokey/centralroom","center",
           AAREA+"main_dr1","village",
           "players/arthur/quest/entrance","quest",
         "Hehehe, this is Arth's workroom.",
         "    There are many toys and gagets laying around, but you probably shouldn't\ntouch anything. Knowing Arthur, you may get shocked hurt, or even killed by\nplaying with his personal toys. And some of the other toy's may be very fun to\n"+
    "play with. Just please be careful when playing with any toy's laying in this\nworkroom.\n",1)
init() {
      add_action("emote", "emote");
      add_action("invis", "hideme");
      add_action("echo", "roomecho");
      add_action("put", "put");
      add_action("get", "get");
       ::init();
        
        }
invis() {
   if(!TP()->query_immortal()) {write("hum not for you\n"); return 1;}
     TP()->set_invis(TP()->query_level());
     write("You are now invis: "+TP()->query_level()+".\n");
     return 1;
    }
emote(str) {
    if(!str) return 0;
     write("You emote: "+str+"\n");
     say(capitalize(TP()->query_real_name())+" "+str+"\n");
    return 1;
   }
echo(str) {
    say(str+"\n");
    write("You echo: "+str+"\n");
    return 1;
}
get(str) {
    if(str !="bird from cage") return 0;
    else
    if(bird) {write("The bird is already out of the cage.\n"); return 1;}
    else {
    write("You take the bird out of the cage.\n");
    say(TP()->query_name()+" lets Otis out of the cage.\n");
      bird=clone_object("/players/arthur/area/monsters/otis");
      move_object(bird,this_object());
      return 1;}
}
put(str) {
    if(str !="bird in cage") return 0;
    if(!bird) {write("Otis is still in the cage.\n"); return 1; }
    else {
      write("You put Otis in the cage.\n"); say(TP()->query_name()+" puts Otis in the cage.\n");
      destruct(bird);
      return 1;}
}
