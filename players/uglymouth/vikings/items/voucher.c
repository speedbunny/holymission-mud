/* permission to use the rowboat */
inherit "obj/thing";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("voucher");
      set_alias("permission voucher");
      set_short("A permission voucher");
      set_value(50);

      }
   }
