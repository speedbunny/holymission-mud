/* wateralemental and spirit of the borderriver */
inherit "obj/monster";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("fire-elemental");
      set_alias("elemental");
      set_short("A fire-elemental");
      set_long("The firespirit rises from the flames as a giant burning fist. \n");
      set_level(15);
      set_al(-150);
      set_ac(10);
      set_aggressive(1);
      }
   }


