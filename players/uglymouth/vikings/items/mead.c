/* the vikings' favorite drink */
inherit "obj/alco_drink";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("mead");
      set_alias("mug of mead");
      set_short("A mug of mead");
      set_long("This alcoholic honey drink is the most favorite and holy "+
               "drink of the vikings. \n");
      set_value(150);
      set_strength(25);
      set_drinker_mess("Gulp! AAAaaaaahh!! It tastes devine... \n");
      set_drinking_mess(" feels in Walhalla as "+
            this_player()->query_pronoun()+" empties a mug of mead. \n");
      set_empty_container("mug");
      }
   }
