/* thor, the god of thunder */
inherit "obj/monster";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
   set_name("thor");
   set_short("Thor, hammerer of thunder and lover of war");
   set_long("Thor, viking god of T H U N D E R ! \n"
          + "Next to Odin the mightiest of vikings. \n"
          + "He is strong and easy to anger, so beware, O Daring One. \n");
   set_level(20);
   set_al(1000);
   set_race("deity");
   set_gender(1);
   }
}

void irritated(int i) {
   write("Thor says: You will never make it, mortal! \n"
       + "Thor laughs his THUNDEROUS laugh. \n");
   environment(this_object())->set_busy(0);
   return;
   }
