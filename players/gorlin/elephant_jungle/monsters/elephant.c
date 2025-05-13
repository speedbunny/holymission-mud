/* Gorlin, 15.10.1996 */

inherit "obj/monster";

reset (arg) {
   ::reset (arg);
   if (arg) return;

   set_name("elephant");
   set_race("elephant");
   set_short("Elephant");
   set_long("A large grey elephant, eyeing you suspiciously.\n");
   set_level(14);
   set_hp(600);
   set_n_wc(16);
   set_n_ac(6);
   set_gender(random(2)+1);
   set_al(70);
   return 1;
}
