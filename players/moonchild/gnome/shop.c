inherit "room/shop";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  property=({ "no_steal", "no_teleport" });
  set_short("The shop");
  set_long(
"You are in the Gnomes' shop. You can buy or sell things here.\n"+
"Commands are: 'buy item', 'sell item', 'sell all', 'list', 'list weapons'\n"+
"'list armours' and 'value item'.\n");
  set_store_room("players/moonchild/gnome/shop/store");
  set_store_exit("west");
  set_exits(({"players/moonchild/gnome/alley1","east" }));
  set_light(1);
}
