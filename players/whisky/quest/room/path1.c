

inherit "room/room";

#include "../monkway.h"
reset(arg) {
    if (!arg) {

    set_light(1);
    short_desc = "On a narrow path";
    no_castle_flag = 0;
    long_desc = 
   "You are climbing up a steep path towards the snowcovered,\n"
   + "eastern mountains. When you look down you see a deep stony\n"
   + "ravine. The bottom where you walk is covered with big stones\n"
   + "made of granite. There is some grass growing between the stones.\n"
   + "The path leads steep further up into the snowcovered mountains.\n"
   + "\n";
    dest_dir = 
        ({
        PATH+"ravine3", "down",
        PATH+"path2", "up",
        });
    items = ({
     "bottom",
     "The bottom is stony and covered with some grass.\n"
     + "",
     "grass",
     "The grass grows between the big stones.\n"
     + "",
     "mountains",
     "The mountains are high and snowcovered. \n"
     + "",
     "ravine",
     "If you look down you see a deep ravine.\n"
     + "",
     "stones",
     "Some big granite stones.\n"
     + "",
     });
   }
}

