/* Gorlin, 15.10.1996 */

inherit "obj/monster";

void reset (int arg) {
   ::reset (arg);
   if (arg) return;

   set_name("tiger");
   set_race("tiger");
   set_short("A Tiger is stalking you");
   set_long("A large tiger, looking rather hungry. Better be "+
      "alert and ready for trouble.\n");
   set_level(15);
   set_n_wc(17);
   set_n_ac(3);
   set_gender(random(2)+1);
   set_al(-90);
   set_aggressive(1);
   return;
}
