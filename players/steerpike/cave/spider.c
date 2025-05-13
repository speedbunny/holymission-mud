inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("spider");
  set_short("A small poison spider");
  set_long("This is a nasty little poison spider.\n");
  set_aggressive(1);
  set_level(5);
  set_hp(1000);
  set_ac(0);
  set_chance(0);
  /* Matt JUN-26-94: Made wc always 10 instead of sometimes 80 */
  set_wc(10);
}

/* Matt JUN-26-94: Poisonous spider can actually poison (!!)
   Added to compensate for lower wc, above, and to match the description */

attack() {
  object opponent;
  opponent = query_attack();
  if(opponent && !random(10)) {
    opponent->add_poison(20);
 /* Tatsuo boosted poison level to discourage use as infinite xp source
    Player can handle one spider but constantly ringing bell not worth
    poison damage.  If not successful, must remove the spider
*/
    tell_object(opponent, "You are poisoned by a bite from the spider!\n");
  }
  ::attack();
}
