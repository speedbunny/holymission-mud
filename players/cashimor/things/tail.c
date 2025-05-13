inherit "obj/weapon";

int daggers;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("tail");
    set_alias("dragon tail");
    set_short("A silver dragon tail");
    set_long("This is the tail of a giant silver dragon. It is an awesome\n"
           + "weapon, for someone as strong as a dragon at least... It's\n"
           + "covered with sharp silver points, like daggers.\n");
    set_class(15);
    set_weight(15);
    set_value(1500);
    set_hit_func(this_object());
    set_two_handed(1);
    this_object()->set_type(1);
  }
}

weapon_hit(who) {
  if(wielded_by->query_race()=="dragon") {
    if(random(8)==1)
      tell_object(who,"You're hit by the dragon's tail!\n");
    return 15;
  }
}

