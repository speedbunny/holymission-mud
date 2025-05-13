#include "mroom.h"

reset(arg){
    if(arg) return;
    set_light(1);
    short_desc="Thain's office";
    long_desc=
    "This is the thain's office. It's a big place with a large desk\n"+
    "and two chairs, not to mention his highbacked leather chair.\n"+
    "You don't think it will be such a good idea to poke around\n"+
    "his office.\n";
    dest_dir=({
      SHIRE+"/sheriff2", "west",
    });
    items=({
      "desk", "A large oak desk",
      "chair", "The thain's chair",
      "chairs", "Chairs for the thain's visitors",
    });
    clone_list = ({1,1, "thain", SHIRE+"/thain", 0,
    });
    ::reset();
    replace_program("room/room");
}
