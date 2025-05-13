/* Gorlin, 15.10.1996 */

inherit "obj/monster";

reset (arg) {
   ::reset (arg);
   if (arg) return;

   set_name("elephant bull");
   set_alias("bull");
   set_race("elephant");
   set_short("Elephant Bull");
   set_long("A large massive elephant bull, guarding his herd.\n");
   set_level(19);
   set_hp(900);
   set_n_wc(17);
   set_n_ac(6);
   set_gender(1);
   set_al(0);
   return 1;
}
