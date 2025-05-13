inherit "/obj/std_shop";

void reset(int arg) {

  if(arg) return;

  ::reset(arg);

  set_light(1);

  short_desc="Animal's shop of horrors";
  long_desc="You are in Animal's little shop of horrors.  This place is " +
            "full of neat little items (sometimes!).  Occasionally there "+
            "are some magical or really useful items for sale.  You can " +
            "buy, sell, list, and value items here.\n";

  store="/players/emerald/good/shops/store";
  keeper="Ogden";

  dest_dir=({"/players/emerald/good/shops/shop_street3", "south",
           });

  items=({"counter","The service area of the shop",
  });

  move_object(clone_object("/obj/torch"),query_store());
  move_object(clone_object("/players/cashimor/objects/match"),query_store());
  move_object(clone_object("/players/emerald/good/obj/boots"),query_store());

}
