object owner;
int lngth;

void dest_shad();

status spam_shad() { return (1); }

void start(object pl) {
  owner = pl;
  lngth = owner->query_int() * 5;
  shadow(owner,1);
}

status restore_spell_points(int num) {
  lngth--;
  if (lngth < 1) dest_shad();
  if (num > -1) {
    owner->restore_spell_points(num);
    return (1);
  }
  num = num / 2;
  owner->restore_spell_points(num);
  return (1);
}

void dest_shad() {
  tell_object(owner, "\nYou feel your added spellcasting ability fade away.\n");
  unshadow();
  destruct(this_object());
}
