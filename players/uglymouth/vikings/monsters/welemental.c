/* wateralemental and spirit of the borderriver */
inherit "obj/monster";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("water elemental");
      set_alias("elemental");
      set_short("A water elemental");
      set_long("The riverspirit looks like a giant fist of solid water. \n");
      set_level(15);
      set_al(-100);
      set_ac(10);
      set_aggressive(1);

      }
   }
