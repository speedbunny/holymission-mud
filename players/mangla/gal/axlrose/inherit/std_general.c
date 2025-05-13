inherit "/obj/mon";

void mobilize(string room) {
  object ob;

  if(environment())
    return;
  else {
    ob=find_object(room);
    if(ob)
      move_object(this_object(),ob);
  }
}

int monster_died() {
  return 0;
}

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_dead_ob(this_object());
  }
}
