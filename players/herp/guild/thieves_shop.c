inherit "room/shop_inherit";

reset(arg) {
   if (arg) return;
   set_short("The Fence");
   set_long("You have entered the Thieves Fence of Realmsmud.\n"+ 
      "Items that you find while adventuring may be bought and sold here.\n"+
      "Commands are:\n"+
      "'buy item', 'sell item', 'sell all', 'list', 'list weapons',\n"+
      "'list armors' and 'value item'.\n"+
      "Behind a small sales counter, there is a hall leading north.\n"+
      "A sign up above the hall reads: MANAGEMENT ONLY\n");
  set_store_room("obj/guild/store");
   set_store_exit("north");
   set_exits(({"obj/guild/thief_guild","east"}));
   set_light(1);
  set_property("no_fight");
}
