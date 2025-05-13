inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

reset(arg){
   if(!arg){
   set_light(1);
   short_desc="In an ancient graveyard";
   long_desc="You stand in an ancient graveyard.  The ground is soggy and "+
             "covered with strange moss.  To the west there is a large "+

             "granite structure.  There is a message written in blood "+
             "on a nearby tombstone.\n";
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
}

int read(string str) {
  if(str == "message") {
    write("The message reads: HELP!!\n");
    return 1;
  }
  notify_fail("Read what ??\n");
  return 0;
}
/*
int read(string str) {
   if(str=="message") {
   write(
   "It reads: HELP!!\n"
   );
 }

   if(str=="read")
     write("Read what??\n");
  return 1;
}
*/
