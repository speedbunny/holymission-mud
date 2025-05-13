inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

read(arg){
  if (arg!="sign"){
write("Read what?\n");
return 1;
}
if (arg=="sign"){
write(
"\n"+
"Warning to my goblin minions,\n"+
"\n"+
"I have but a protective seal over this sinkhole in response to the\n"+
"fact that several of you have fallen into it and asked me for help\n"+
"Please do not tamper with anything in this room as it may cause trouble\n"+
"with the seal.\n"+
"\n"+
"Darkstaff\n");
return 1;
}
}

void reset(int arg){
  short_desc = "A huge sinkhole";
  long_desc =
"This walls of this room are made almost entirely of limestone.  A huge "+
"sinkhole dominates the center of the room.  It decends into the darkness "+
"of the heart of the mountain.  Someone has posted a sign on the wall\n";
  set_light(0);
  dest_dir = ({
    sr+"/room210","northwest",
    sr+"/room212","east",
  });
 items = ({
    "walls",
    "Limestone makes up most of the composition of these walls",
    "sign",
    "A sign, perhaps you should read it..",
    "sinkhole",
    "A huge sinkhole with steep sides, watch your step!",
         });
    ::reset(arg);
}

void init(){
  ::init();
  add_action("read","read");
  }

