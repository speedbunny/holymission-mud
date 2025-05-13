inherit "room/shop";

reset(arg) {
  ::reset(arg);
  property="no_steal";
  short_desc = "The Coalminer shop";
  long_desc =
  "You are in a small coalminer shop, here the coalminers do their daily \n"+
  "shopping for a living.\n"+
  "You can use 'buy item','sell item','value item','sell all','list' \n"+
  "'list armours' and 'list weapons'.\n"+
  "It's just a normal shop as any others.\n";
  set_store_room("room/store");
  set_store_exit("north");
  set_exits(({"players/dice/rooms/vill6","west" }));
  set_light(1);
}
