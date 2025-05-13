inherit "room/room";
#include "/players/saffrin/defs.h"


reset(arg){
    set_light(2);
    short_desc = "Joy's Park";
    long_desc =
         "You are standing in the middle of Joy's Park.  There is a large fountain "+
         "with clear water sprouting from its center.  The water looks good enough to 'taste'."+
         "  You can hear birds flying above but are unable to see them with the strong "+
         "sun in your eyes.\n";
    dest_dir=({
      TINK+"room/joy1", "north",
      TINK+"room/joy5", "south",
      TINK+"room/joy3", "east",
      TINK+"room/joy11", "west",
    });
    items=({
      "fountain", "A large marble fountain with a spout in its center",
      "spout", "A spout shooting out water",
      "water", "Clear water, perhaps you can 'drink fountain'",
      "birds", "Silly!  You can't see them.  The sun is too strong",
      "sun", "ARGH!!!!!!!  You feel you eyeballs burning in pain",
    });
    clone_list=({
          1, 1, "butterfly", TINK+"npc/butterfl", 0,
          1, 1, "cardinal", TINK+"npc/cardinal", 0,
          1, 1, "robin", TINK+"npc/robin", 0,
          1, 1, "chipmunk", TINK+"npc/chipmunk", 0,
    });
    ::reset();
}

init(){

  ::init();
    AA("drink", "drink");
    AA("drink", "taste");
    return 1;
}

drink(str){

  if(str!="water") return 0;
    ME("You step up to the fountain, cup your hands and\n");
    ME("take a large sips of water.\n");
    ME("\n");
    ME("You turn green and puke all over you shoes when you notice\n");
    ME("a bird plopping in the fountain.\n");
    ME("\n");
    ME("The bird laughs at you.\n");
    say(TPQN+" drinks from the fountain.\n");
    say(TPQN+" turns green.\n");
    say(TPQN+" pukes all over the place.\n");

  return 1;
}
