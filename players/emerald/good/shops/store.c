inherit "/room/room";

reset(arg) {
  ::reset(arg);
  long_desc="The storeroom of the shop.  Exciting, eh?\n";
  dest_dir=({"/players/emerald/good/shops/shop","up"
           });
  set_light(1);
}

