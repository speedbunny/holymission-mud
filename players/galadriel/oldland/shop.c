#include "/players/skeeve/area.h";

inherit "room/shop";

reset(arg) {
  ::reset(arg);
  set_short("The shop"); /* Short desc */

  set_long(
     "######################################################\n"
    +"                   DRUID LAKMIR'S SHOP\n"
    +"######################################################\n"
    +" You can buy or sell things here.\n"
    +"Commands are: 'buy item', 'sell item', 'sell all', 'list',\n"
    +"'list weapons', 'list armours' and 'value item'.\n");

  set_store_room("room/store"); /* Room used for storing items in -
                   use "room/store" to share with the
                   main shop, make your own otherwise */

  set_store_exit("north"); /* Exit into the store room */

  set_exits(({LAND+"fork","out"})); /* Exits from the room */

  set_light(1); /* You don't need a torch */
}
