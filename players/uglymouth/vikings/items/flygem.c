/* might one day be part of Galadriels eagle system */
inherit "obj/treasure";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("topal");
      set_alias("gem");
      set_short("A topal");
      set_long("A small but beautiful grey-blue gemstone. \n");
      set_value(100);

      }
   }
