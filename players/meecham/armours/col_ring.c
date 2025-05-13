inherit "/obj/armour";

static object owner;
int rate;

void reset (status arg) {
  ::reset(arg);
  if (arg) return;
  set_short("Coldrik's ring of power");
  set_long("Coldrik's ring of power glows a bright golden color and seems\n"+
                "to throb softly.\n");
  set_weight(1);
  set_type("ring");
  set_value(2500);
  set_ac(1);
  set_name("Coldrik's ring of power");
  set_alias("ring");
  set_arm_light(2);
}

heart_beat() {

  if (!environment(this_object()))
    destruct(this_object());

  if (!owner && interactive(environment(this_object())))
    disable_commands();
  else if (!interactive(environment(this_object()))) {
    disable_commands();
    destruct(this_object());
  }
  owner->reduce_hit_point(-(rate+2));
  if (owner->query_hp() > owner->query_max_hp())
    owner->reduce_hit_point(owner->query_hp() - owner->query_max_hp());
}

int wear(string arg) {
  if (!id(arg)) return (0);
  if (::wear(arg)) {
    owner = this_player();
    rate = (this_player()->query_level()+
              this_player()->query_legend_level())/7;
    tell_object(owner,"You feel your ring come to life.\n");
    enable_commands();
    set_heart_beat(1);
  }
  return( 1 );
}

int remove(string arg) {
  if (id(arg)) {
    tell_object(owner,"Your ring seems to fade a little.\n");
    set_heart_beat(0);
    disable_commands();
  }
 return ::remove(arg);
}

object owner() { return (owner); }
string owner_name() { return (owner->query_name()); }


void remove_fun(object player) {
  set_heart_beat(0);
  disable_commands();
}
