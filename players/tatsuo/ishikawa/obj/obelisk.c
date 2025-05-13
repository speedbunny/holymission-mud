inherit "obj/thing";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
#define TP this_player()
object key;
int unlck, opn;

reset(arg){
if(arg) return;
unlck=0;
key=present("tatskey",TP);
opn=0;
set_name("obelisk");
set_short("A Great Obelisk");
set_long(break_string("A Great Obelisk towers up through the jungle "+
	"canopy here.  Ancient runes and tangled vines cover the "+
	"surface of the obelisk.  A huge stone door is set at the "+
	"base of the great structure.\n",65));
set_weight(100);
}
init(){
::init();
  AA("_unlock","unlock");
  AA("_open","open");
  AA("_enter","enter");
}
_unlock(){
    if(unlck<0){ write("The door is already unlocked.\n");
   }
    if(present("tatskey",TP)){
    write("You put the great key in the lock and struggle to turn it. CLICK\n");
    destruct(present("key",TP));
    unlck=1;
    return 1;
     }
    else{
     write("You do not have the right key.\n");
     return 1;
    }
}
_open(){
   if(opn<0){ write("The door is already open.\n"); }
  if(unlck<0){
   write("The door is locked.\n");
   return 1;
   }
  if(unlck==1){
    if(TP->query_str()<20){
     write("The door is too heavy for you to pull open.\n");
     return 1;
     }
    else {
     write("You pull the Huge stone door open.\n");
     opn=1;
     return 1;
    }
   }
}
_enter(){
  if(opn<0){
  write("The door appears to be closed.\n");
  return 1;
  }
  if(opn==1){
   MOVE("into the obelisk#/players/tatsuo/ishikawa/INobelisk");
   }
}
