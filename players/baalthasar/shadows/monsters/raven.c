inherit "obj/monster";
  reset(arg) {
  ::reset(arg);
  if(!arg) {
  set_name("Raven");
  set_alias("raven");
  set_long("This raven seems to watch you with intently.  Its eyes \n"+
"reflect great intelligence and understanding. \n");
  set_al(0);
  set_aggressive(0);
  set_level(30);
  set_hp(1800);
  set_ac(20);
  set_wc(7);
}
  }
attack() {
 if(this_object()->query_attack()) {
  say(" \n");
  say("The raven jumps into the sky and squawks: \n"+
"       FOOLS!!  We shall meet once again!  Beware!! \n\n");
  say("The raven darts northwards and vanishes in seconds... \n\n");
  destruct(this_object());
return 1;
 }
::attack();
}
