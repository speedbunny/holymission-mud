/* SHOP.C - Programmed by Animal */
/* 170993: Ethereal Cashimor: Removed bug */

#include "/obj/lw.h"

inherit "room/shop";

init() {
  ::init();
  add_action("read","read");
}

reset(arg) {
  if(!arg) {
    set_short("Animal's shop of horrors");
    smell="The shop is very clean.";
    items=({"sign","Please, read it"});
    set_long("Animal's place. You are in Animal's little shop of horrors. "
           + "This place is full of neat little items (maybe). You can "
           + "sometimes find magical items here for sale. There is a sign "
           + "here, read it.\n"
           + "Buy, sell, list or value?\n");
    set_light(1);
    set_exits(({"players/animal/shops/shop_street3","south"}));
    set_store_room("players/animal/shops/store");
    set_store_exit("north");
  }
}

read(str) {
  if((!str)||(str!="sign")) {
    notify_fail("Read what?\n");
    return 0;
  }
  writelw("Animal's World. This is a small part of the world of Animal. You "
        + "can have may adventures in his fun world, all of them different. "
        + "Just look around and search around, you will never know what you "
        + "may find. ENJOY!\n");
  return 1;
}

