/* SHOP.C - Programmed by Llort */
/* 170993: Ethereal Cashimor: Changed to room and using shop */

inherit "room/shop";
#define TP this_player()

reset(arg) {
  ::reset(arg);
  if(!present("trashcan",this_object())) {
    move_object(clone_object("/players/whisky/shops/trashcan"),this_object());
  }
  if(!arg) {
    set_exits(({"players/llort/guild/tower/hallway","east"}));
    set_short("Gondies general store");
    smell="The shop smells rather clean.";
    set_long("You are in Gondies general store. You can buy or sell things "
           + "here. Commands are: 'buy item', 'sell item', 'sell all', "
           + "'list', 'list weapons', 'list armours' and 'value item'.\n");
    set_store_room("players/llort/guild/tower/store");
    set_store_exit("west");
    set_light(1);
  }
}
