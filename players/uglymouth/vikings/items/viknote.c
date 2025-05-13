/* some hints on a clay tablet */
inherit "obj/treasure";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("tablet");
      set_alias("clay tablet");
      set_short("A clay tablet");
      set_long("There's something written on it. \n");
      set_value(7);
      set_read("When fire and water have formed the steam \n"
             + "Go then to the holy oak to dream \n"
             + "Spend one night is what it will take \n"
             + "For in Walhalla it is you wake \n");

      }
   }
