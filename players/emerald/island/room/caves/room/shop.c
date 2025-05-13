inherit "/obj/std_shop";
void reset(int arg) {
  ::reset(arg);
  short_desc="In the Orc shop";
  long_desc="You have entered a rather well-lit cave.  An orc stands behind "+
            "a counter, behaving rather civilly for an orc.  You gather that "+
            "this is a shop of some sort.  There is a sign reading, 'type "+
            "list' behind the counter.\n";
   set_light(1);
   store = "/players/emerald/island/room/caves/room/store";

  items=({"cave","This cave is actually a shop in disguise",
          "orc","He appears to keep the store",
          "counter","A long low counter, made of wood",
          "shop","It's rather dingy and dirty",
          "sign","It hangs behind the counter",
            });

  dest_dir=({"/players/emerald/island/room/caves/room/ci6","west"
          });

  move_object(clone_object("/players/whisky/obj/torch"),query_store());
  move_object(clone_object("/players/whisky/obj/recall_scroll"),query_store());

  if(!present("trashcan",this_object()))
    move_object(clone_object("players/whisky/shops/trashcan"),this_object());
}
