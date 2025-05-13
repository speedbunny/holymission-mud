#define TPN this_player()->query_name()
inherit "obj/weapon";

reset(arg) {
  ::reset();
  if(arg) return;
  set_name("Unholy Sword");
  set_short("A glowing black sword");
  set_alias("sword");
  set_long("It is a sword of fine workmanship, so evil it absorbs light.\n");
  set_class(17);
  set_value(5400);
  set_weight(3);
  set_hit_func(this_object());
  set_wield_func(this_object());
}

weapon_hit(attacker) {
  if(this_player()->query_alignment()>-100) return 0;
  if(attacker->query_alignment()<100) return 0;
  write("The blade senses good and hits hard!\n");
  say(this_player()->query_name()+" disembowels "
    + this_player()->query_possessive()+" opponent.\n");
  return 21;
}


wield(str) {
  if(!id(str)) return 0;
  if(environment()!=this_player()) return 0;
  if(wielded) {
    write("You've already wielded the sword!\n");
    return 1;
  }
  if(this_player()->query_alignment()>0) {
    write("Only a very evil person may wield the Unholy Avenger.\n"
        + "You can't wield it...\n");
    this_player()->reduce_hit_point(random(30));
    say(TPN+" tried to wield the Unholy Avenger, but got burned by it.\n");
    return 1;
  }
  wielded_by=this_player();
  this_player()->wield(this_object());
  wielded=1;
  write("You wield the Unholy Avenger!\n" +
        "You feel the evil ebbing throughout your body.\n"+
        "You feel this sword was made to kill good monsters.\n");
  return 1;
}
