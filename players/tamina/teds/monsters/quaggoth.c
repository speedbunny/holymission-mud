inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
   set_name("quaggoth");
   set_race("ape");
   set_alias("snow ape");
   set_short("A Snow White Quaggoth");
   set_long("This race of snow apes has developed rudementary intelligence.\n");
   set_level(8);
   set_hp(150);
   set_ep(100000);
   set_ac(4);
   set_wc(15);
   set_al(-100);
}
