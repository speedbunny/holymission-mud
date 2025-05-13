inherit"room/room";
#include "/players/wilbie/def.h"
object ob;
int counter;
/*Wilbie*/

reset(arg){

counter=0;
   if(!arg){
   set_light(1);
   short_desc="In an ancient graveyard";
   long_desc="You stand in an ancient graveyard.  The ground is soggy and "+
  "the moss is much thicker here.  Maybe you could scrape some up? "+

 "There is a message written in what looks like blood on a nearby "+
  "tombstone.\n";
   items=({"moss","It is an odd color of green",
           "message", "It reads:  HELP!!!",
   "ground","It is soggy ground",
   "tombstone","It is blank, except for the message in blood",
   "structure","An old church of very large size",
   "church","A cathedral of some sort",
   "blood","Old, dried blood",
           "graveyard","It is old and in ill-repair"});

    dest_dir=({
    GPATH+"e_grave2", "north",
    });
 }
::reset(arg);

}
void init() {
   ::init();
   add_action("read","read");
   add_action("dig","dig");
   add_action("dig","scrape");
}

int read(string str) {
  if(str == "message") {
    write("The message reads: HELP!!\n");
    return 1;
  }
  notify_fail("Read what ??\n");
  return 0;
}
int dig(string str) {
  if(str == "moss") {
     if(counter <= 5) {
  ob=clone_object("/players/wilbie/graveyard/moss");
  transfer(ob,this_player());
  write("You got some moss.\n");
  counter++;

}
  else write("There is no moss left that can be taken.\n");
  return 1;
}


  notify_fail("A little more specific, please?\n");
  return 0;
}
