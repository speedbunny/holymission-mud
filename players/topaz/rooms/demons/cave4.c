inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {

     short_desc = "A huge cavern";
     long_desc = "Wow!  You are impressed at the size of this cavern.\n" +
                 "It's hard to believe that something this big can be\n" +
                 "underground.  There is a large fire in the center of\n" +
                 "the cave which produces enough light that you have\n" +
                 "to squint.  Even so, you can just barely make out the\n" +
                 "roof of the cavern.  It is way up there!\n";

      dest_dir = ({"players/topaz/rooms/demons/cave3","north",
                   "players/topaz/rooms/demons/cave5","south",
 
                     });

    items =({"cavern","This place is just huge",
              "roof","You can just barely make out the shape of the roof",
              "fire","A huge bonfire.  Must be for some celebration or ceremony",
              });
       set_light (3);
      smell = "All you can smell is smoke from the fire.";
       property=({"has_fire"});
    clone_list=({ 1, 3, "demon Dancer", MDEMONS + "dancer",
        ({"set_name","demon Dancer",
          "set_long","An ugly demon.\n" +
          "This demon dancer blah.\n" +
          "It has a tattoo of a white crown on its chest.\n", }),
                  2, 3, "demon Dancer", MDEMONS + "dancer2",
        ({"set_name","dancing Demon",
          "set_long","An ugly demon.\n" +
          "This demon dancer blah.\n" +
          "It has a tattoo of a white crown on its chest.\n", }), });
    ::reset();
  replace_program("room/room");
}
