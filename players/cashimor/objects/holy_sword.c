inherit "obj/weapon";

reset(arg) {
  set_name("holy sword");
  set_short("A Holy Sword");
  set_long("This is a holy sword. Use it only for saintly purposes...\n");
  set_class(9);
  set_value(2500);
  set_weight(2);
  set_hit_func(this_object());
  set_info("Cashimor's great Holy Sword.");
}

weapon_hit(attacker) {
  if(this_player()->query_alignment()<100) return 0;
  if(attacker->query_alignment()>-100) return 0;
  write("You disembowel your enemy!\n");
  say(this_player()->query_name()+" disembowels "
    + this_player()->query_possessive()+" opponent.\n");
  return 21;
}

wield(str) {
  if(!id(str)) return 0;
  if(environment()!=this_player()) return 0;
  if(wielded) {
    write("You've already wielded the Holy Sword!\n");
    return 1;
  }
  if(this_player()->query_alignment()<0) {
    write("The Holy Sword dislikes you! It burns!\n"
        + "You can't wield it...\n");
    this_player()->reduce_hit_point(random(30));
    say(this_player()->query_name()+" tries to wield a holy sword, but got burned by it.\n");
    return 1;
  }
  wielded_by=this_player();
  this_player()->wield(this_object());
  wielded=1;
  write("Ok.\n");
  return 1;
}

