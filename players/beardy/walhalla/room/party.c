inherit "room/room";
#include "../walhalla.h"

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Partyroom",
    long_desc="This is the divine party-room of Walhalla. You see\n" +
              "lots of gods around not only them of Walhalla. This\n" +
              "seems to be a big party of all gods and they are all\n" +
              "drunk. Oops, they feel disturbed by you and - oh my god -\n" +
              "they attack you.... \n";

    items=({"stairs","What huge ones !",
            "wind","HUI.... It's gone..."});


    dest_dir =({ROOM + "up4","south"});

    smell = "It smells very unnatural in here.";

    property=({"no_hide"});
  CM("krokin");
  CM("hel");
  CM("hera");
  CM("poseidon");
  CM("hermes");
  CM("teutates");
  }
}
