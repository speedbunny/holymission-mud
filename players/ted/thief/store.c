inherit "room/store_inherit";

reset(arg) {
  ::reset();
   if (arg) return;
   set_short("General Store storage room");
   set_long("This is the storage room for the General Store. The only exit\n"+
      "you can see is down.\n");
   set_shop("players/ted/thief/shop");
   set_shop_exit("south");
   set_light(1);
}
