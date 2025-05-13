inherit "/obj/armour";

static object owner;
int rate;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  owner = this_player();
  rate = (this_player()->query_level()+
             this_player()->query_legend_level())/5;
  set_short("A silver shimmering headband");
  set_long("The band is made of silver with a lot of magical runes\n"+
                "engraved along. It is radiating magic.\n");
  set_weight(1);
  set_type("helmet");
  set_value(1);
  set_ac(1);
  set_name("headband");
  set_alias("band");
}

void heart_beat() {
  if(!environment() || !interactive(environment()) || !owner) {
    disable_commands();
    destruct(this_object());
  }
  else if(query_worn())	// Added by Sauron to stop multiple heals...
    owner->restore_spell_points(rate+2);

// Added by Meecham as a 'better yet' solution
#if 0
// Sauron: This is not a better solution since it stops the headband from
// being destructed when it's environment is a room.
  if(!query_worn()) {
    set_heart_beat(0);
    return;
  }
#endif // 0
}

int wear(string arg) {
  if(arg!="headband")
    return 0;
  else if(!owner || owner!=this_player()) {
    notify_fail("This is not your headband.\n");
    return 0;
  }
  else if(::wear(arg)) {
    if(owner->query_guild()==2) {
      tell_object(owner,"You feel the power of nature.\n");
      enable_commands();
      set_heart_beat(1);
    }
    return 1;
  }
}

int remove(string arg) {
  if(id(arg) && query_worn()) {
    if(owner->query_guild()==2) {
     tell_object(owner,"The power of nature leaves your body.\n");
     set_heart_beat(0);
     disable_commands();
   }
 }
 return ::remove(arg);
}

object owner() {
  return owner;
}

string owner_name() {
  return owner->query_name();
}

void remove_fun(object player) {
  set_heart_beat(0);
  disable_commands();
}
