inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
reset(arg){
    if(arg) return 1;
    set_light(1);
    short_desc="the south shore of Ishikawa";
    long_desc=break_string(
      "You have arrived on the coast of a small island.  To the north a "+
      "mountain towers over the surrounding jungle.  An old dock extends "+
      "into the ocean water, and a path extends into the jungle to the "+
      "north.  The coast extends to the northwest and northeast.\n",65);


    items = ({
      "dock","An old dock, perhaps if you wait long enough a ship might come",
      "water","It looks wet",
      "path","It leads north",
      "coast", long_desc,
    });
    property=({
                "no_clean_up",
    });
    dest_dir=({
      IPATH+"beach2.c","northwest",
        "/players/patience/ezo/coast/sh14","ocean",
      IPATH+"beach3.c","northeast",
      IPATH+"jung1.c","north",
    });
/*
    move_object(clone_object("/players/tatsuo/ishikawa/sampan"),
                this_object());
   */
    ::reset(arg);
}
