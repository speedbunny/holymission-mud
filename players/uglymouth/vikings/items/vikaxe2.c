/* a typical viking weapon */
inherit "obj/weapon";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("viking axe");
      set_alias("axe");
      set_alt_name("A viking axe");
      set_short("A viking axe");
      set_long("A heavy double-bladed axe. \n"
             + "It's strangely curved blades are deadly sharp. \n");
      set_class(14);
      set_value(700);

      }
   }
