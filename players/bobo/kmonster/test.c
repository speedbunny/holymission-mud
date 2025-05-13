inherit "obj/monster";
 
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_level(15);
 set_name("orc");
 set_level(20);
 set_al(-150);
 set_race("orc");
 set_size(3);
 set_short("An Orc");
 set_long("An ugly Orc, probably an Uruk-hai.\n");
 set_aggressive(1);
}
 
hit_player(dam,i) {
  say("HIT_PLAYER: "+dam+"\n");
  return ::hit_player(dam,i);
}
 
reduce_hit_point(dam) {
  say("REDUCE_HIT_POINT: "+dam+"\n");
  return ::reduce_hit_point(dam);
} 
