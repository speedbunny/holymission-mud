inherit "obj/weapon";

reset(arg) {
  if(arg) return;
 
  set_name("mega-wand");
  set_alias("wand");
  set_short("A Mega-Wand");
  set_long("An enormous wand that looks as though it could decapitate \n"+ 
           "the strongest of monsters...\n");
  set_class(150);
  set_value(100000);
  set_weight(5);
  set_type(3);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
if(random(14)<14) {
  write("BBBBOOOOOOOOOOOMMMMMMM!!!!!!!!!\n");
  say("BBBBOOOOOOOOOMMMMMMMM!!!!!!!!!!!!\n");
  return 22;
}
return 0;
}

