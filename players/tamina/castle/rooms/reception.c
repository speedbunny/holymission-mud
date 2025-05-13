#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg){

    set_light(1);
    short_desc = "Reception Area";
    long_desc = 
    "This large, grandiose room was where King Arthur met his honoured\n"+ 
    "guests.  There are windows situated high along the side walls, with\n"+ 
    "weak light filtering through the dirty uncleaned windows.  Tatters of\n"+
    "banners and penants flutter limply in the cold breeze that blows through\n"+ 
    "the cracks in the smashed windows.  Old iron candle-holders swing\n"+
    "precariously from the ceiling, and empty torch-braces on the walls suggest\n"+
    "that this room was once a very bright and happy room.  There are piles of\n"+
    "rotten wood lying all over the room, and pieces of  metal mixed in amongst\n"+ 
    "the wood.  The 3 corridors that lead off from this room are all dark, and\n"+
    "foreboding.\n";

    dest_dir = ({
      CROOMS + "court3","south",
      CROOMS + "guest_room","northwest",
      CROOMS + "kitchen","northeast",
      CROOMS + "throne_room","north",
    });

    items = ({
      "wood", 
      "This appears to have been the old banquet table of this room...\n"+ 
      "It is now way past possible usage",
      "metal", 
      "This would have been the old plates, and goblets and cutlery ",
      "that would have been used at the last banquets",
      "candle-holder",
      "Something like a chandlier, but without any candles",
      "candle-holders",
      "Something like a chandlier, but without any candles",
      "banners",
      "The flags of the King's knights during times of war and "+ 
      "strife, depicting Rampant Lions, Flying Eagles, and other "+
      "emblems of Royal Houses",
      "penants",
      "The old symbols of battles won by King Arthur",
      "windows",
      "The windows can barely be called windows now, since there is very "+
      "little glass left in the frames.  As a result of this, the wind is "+
      "howling through the gaps with an unrestrained fury",
    });

    ::reset (arg);

    RPR("room/room");
}
