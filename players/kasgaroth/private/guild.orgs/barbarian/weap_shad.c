object weapon;

void start_the_shadow(object ob) {
  weapon=ob;
  shadow(ob, 1);
}

void remove_the_shadow() {
  destruct(this_object());
}

int weapon_class() {
  return 3;
}

int hit(object attacker) {
  return ((int)weapon->hit(attacker) + 2 * (int)attacker->query_ac()) / 3;
}

int hit2(object attacker) {
  return (int)weapon->hit2(attacker) / 3;
}

int wield(string str) {
  int tmp;
  tmp=weapon->wield(str);
  if(tmp && (int)this_player()->query_guild()!=11) {
    destruct(this_object());
    return 1;
  }
  return tmp;
}

un_wield() {
  weapon->un_wield();
  destruct(this_object());
}

do_unwield(str) {
  int tmp;
  if(tmp=weapon->do_unwield(str) && !weapon->query_wielded()) {
    unshadow();
    call_out("destme", 1, 0);
    return 1;
  }
  return tmp;
}

void destme() {
  destruct(this_object());
}
