inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
   set_name("fire lizard");
   set_alias("lizard");
   set_short("A Huge Fire Lizard");
   set_long("This large lizard-like creature seems to be on fire.\n"+
"But the fire doesn't seem to be effecting it at all.\n");
   set_level(8);
   set_hp(150);
   set_ac(3);
   set_wc(10);
   set_al(-100);
   set_aggressive(1);
}
