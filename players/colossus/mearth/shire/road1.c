object keeper;
#include "mroom.h"
object keeper;

void reset(int arg){
    ::reset(arg);
    if(!present("keeper")){
	move_object(clone_object(SHIRE+"/keeper"), this_object());
    }
    if(arg) return;
    set_light(1);
    short_desc = "Shire gate";
    long_desc = 
    "This is the gate leading further into a village known as the\n"+
    "Shire. The gatekeeper usually stands here guarding the Shire against\n"+
    "potentially dangerous people who seek the demise of the hobbits.\n";
    dest_dir=({
      SHIRE+"/road2", "north",
      SHIRE+"/entrance", "south",
    });
    items=({
      "gate", "A large sturdy gate meant to keep out troublemakers",
    });
}

void init(){
    ::init();
}
