/* a typical viking weapon */
inherit "obj/weapon";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("viking sword");
      set_alias("sword");
      set_short("A vikings sword");
      set_long("A short but very sharp sword, it's hilt in red and white. \n");
      set_class(10);
      set_value(200);

      }
   }
