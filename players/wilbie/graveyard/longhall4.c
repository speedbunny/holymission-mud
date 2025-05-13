   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(1);
   short_desc="In a narrow passage";
   long_desc=
   "You are in a dimly lit hallway.  Torches provide barely enough light "+
   "to see by, and what little you see is not very reassuring.  There is "+
   "writing scrawled in what might be blood on the northern wall...\n";

  items=({
  "writing","It reads: Beware the magic of the Matriarch",
  "walls","Rusty iron walls",
  "metal","It looks like iron",
  "torches","They offer little light",
  "light","It comes from the torches",
  "blood","It looks pretty old",
  "air","You actually manage to see the air here!  There isn't much "+
        "to look at really, but you can still feel some pride at your "+
        "accomplishment",
  "hallway","You are in the only lit part of a long dark hallway",
  "iron","Very old by the looks of it",
  "floor","An iron floor with some blood dried on it",
  });
  dest_dir=({
   GPATH+"longhall5","west",

   GPATH+"longhall3","east",
   });
  }
::reset(arg);
 }

void init() {
   ::init();
   add_action("read","read");
}

int read(string str) {
    if(str == "writing") {
    write("It reads:  Beware the magic of the Matriarch!!\n");
    return 1;
}
notify_fail("Read what??\n");
return 0;
}
