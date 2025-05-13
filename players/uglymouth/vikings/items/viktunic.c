/* a typical viking armour */
inherit "obj/armour";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("clan tunic");
      set_alias("tunic");
      set_short("A viking clan tunic");
      set_long("A leather tunic in the colours of Hagar's clan.\n");
      set_ac(2);
      set_value(100);
      set_size(0);

      }
   }
