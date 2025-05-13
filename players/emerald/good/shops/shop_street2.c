inherit "/room/room";

void reset(int arg) {

  if (arg) return;

  set_light(1);

  short_desc="Village street";
  long_desc="This is a busy part of the village.  There are peasants " +
            "walking around here, chatting about the cliff and other " +
            "interesting everyday items in the landscape which might " +
            "otherwise go unnoticed to first time visitors of the region.\n";

  items=({"mountains","The mountians are beautiful",
          "village","It's rather noisy right here",
           "cliff","The peasants are discussing it casually",
           "landscape","There might be an unimportant cliff in the landscape",
        });


  dest_dir=({"/players/emerald/good/shops/shop_street3", "north",
            "/players/emerald/good/shops/shop_street1", "south",
          });

  clone_list=({
    1,4,"peasant","/players/emerald/good/obj/peasant",0,
  });

  ::reset();
  replace_program("/room/room");

}
