inherit "obj/monster";
reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("minorva");
    set_alt_name("dragon");
    set_alias("shy dragon");
    set_level(30);
    set_size(4);
    set_weight(80);
    set_gender(2);
    set_hp(1500);
    set_al(-500);
    set_whimpy(100);
    set_race("dragon");
    set_short("Minorva, the shy dragon");
    set_long("You see an eighty-foot high dragon.  She seems a bit "+
             "frightened, but very strong!\n");
    set_wc(30);
    set_ac(10);
    load_a_chat(20,({
      "Minorva hits you with her claw!\n",
      "Minorva thrusts you with her tail!\n",
      "Minorva tries to throw a fireball at you, but fails!\n"}));
}

attack() {
object vic;
int i;
  if(::attack()) {   
    if(random(100)<8) {
      vic=all_inventory(environment(this_object()));
      for(i=0;i<sizeof(vic);i++) {
        if(living(vic[i]) && (vic[i]!=this_object())) {
          vic[i]->hit_player(80+random(60));
          tell_room(environment(this_object()),"Suddenly, Minorva throws "+
                    "a bright ball of fire at you!\n");
          return 1;
        }
      }
    }
  }
  return 0;
}
