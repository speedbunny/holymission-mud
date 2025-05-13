inherit "room/shop";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  property=({ "no_steal", "no_teleport" });
  set_short("The chapel shop");
  set_long(
"You are in the chapel shop. You can buy or sell things here.\n"+
"Commands are: 'buy item', 'sell item', 'sell all', 'list', 'list weapons'\n"+
"'list armours' and 'value item'.\n");
  set_store_room("players/moonchild/gnome/shop/store");
  set_store_exit("west");
  set_exits(({"players/moonchild/chapel/link","north" }));
  set_light(1);
}
