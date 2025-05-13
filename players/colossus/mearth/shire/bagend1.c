#include "mroom.h"

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "North Bag End";
    long_desc =
    "You are walking on North Bag End. Supposedly to the end of this street\n"+
    "is the house of Frodo and Bilbo Baggins. Who knows who you might find there.\n"+
    "You see trees and tidy holes with scenic gardens lining the street and\n"+
    "you feel the peace and carefree feeling that pervades the hobbits' Shire.\n";
    dest_dir = ({
      SHIRE+"/bagend2", "north",
      SHIRE+"/main2", "south",
    });
    items = ({
      "holes", "Nice holes where hobbits live",
      "trees", "Tall well-trimmed trees",
      "gardens", "Beautifully mowed gardens",
    });
}
