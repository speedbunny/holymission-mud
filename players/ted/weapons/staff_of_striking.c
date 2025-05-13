inherit "obj/weapon"; 
int charges;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  charges = 350;
  set_name("Staff of Striking");
  set_alias("staff");
  set_alt_name("staff of striking");
  set_short("An Ironwood Staff");
  set_long("This staff has the head of a snake.\n");
  set_class(8);
  set_weight(3);
  set_value(1400);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
 if(charges >= 0) {
  charges -= 1;
  tell_object(wielded_by,"The staff jerks in your hand like a striking snake!\n");
  return random(30);
 }
 write("But it has expended all its energy.....\n");
 call_other(this_object(), "drop");
 move_object(this_object(),"players/ted/storage");
 return 20;
}
