/* A scroll with hints to be used at the holy oak */
inherit "obj/thing";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("scroll");
      set_alias("leather scroll");
      set_short("A leather scroll");
      set_long("A slightly damaged leather scroll. \n"
             + "There's something written on it. \n");
      set_value(20);
      set_read("Prayer for a deceased viking: \n"
             + "As by ancient ceremony we stood by Odin's tree, \n"
             + "fully dressed in our clan's clothes, our weapons in salute, \n"
             + "to pray for a true viking to be invited to Odin's banquet. \n"
             + "With offering meat of a rabbit as a small fee, \n"
             + "to pay our mighty companion tribute, \n"
             + "now may he feast at his final stay. \n");

      }
   }
