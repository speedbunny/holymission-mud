inherit "obj/monster";
reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("armonophis");
    set_alt_name("dragon");
    set_alias("holy dragon");
    set_level(40);
    set_size(4);
    set_weight(500);
    set_gender(1);
    set_hp(5000);
    set_al(-500);
    set_race("dragon");
    set_short("Armonophis, the Holy Dragon");
    set_long("You see a mighty 120 foot high dragon.  He looks as if he is "+
             "watching something.  Hopefully it isn't you!\n");
    set_ac(10);
    load_a_chat(20,({
      "Armonophits his you with his claw!\n",
      "Armonophis slashes at you with his tail!\n",
      "Armonophis flames you to ashes!\n"}));
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
          tell_room(environment(this_object()),"Suddenly, Armonophis throws "+
                    "a bright ball of fire at you!\n");
          return 1;
        }
      }
    }
  }
  return 0;
}
