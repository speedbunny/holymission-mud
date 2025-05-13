inherit "/obj/armour";

static object owner;
int rate;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  owner = this_player();
  rate = (this_player()->query_level()+
             this_player()->query_legend_level())/5;
  set_short("A wooden ring");
  set_long("The band is made of wood with runes engraved along. It is"+
           " radiating magic.\n");
  set_weight(1);
  set_type("ring");
  set_value(1);
  set_ac(1);
  set_name("ring");
  set_alias("magering");
}

drop()
{
  write("As you remove the ring it fades from sight.\n");
  destruct(this_object());
  return 1;
  }
void init() {
  ::init();
}

void heart_beat() {

  if (!environment(this_object()))
    destruct(this_object());

  if (!owner && interactive(environment(this_object())))
    disable_commands();
  else if (!interactive(environment(this_object()))) {
    disable_commands();
    destruct(this_object());
  }

  if (!query_worn()) 
  {
    set_heart_beat(0);
    return;
    }
  owner->restore_spell_points(rate+2);
}

int wear(string arg) {
  if (arg != "magering") return (0);
  if(::wear(arg)) 
  {
    if (owner->query_guild() == 5) 
    {
      tell_object(owner,"You feel magical.\n");
      enable_commands();
      set_heart_beat(1);
    }
  }
  return( 1 );
}

int remove(string arg) 
{
  if (id(arg) && query_worn()) 
  {
    if (owner->query_guild() == 5) 
    {
      tell_object(owner,"The magic leaves your body.\n");
      set_heart_beat(0);
      disable_commands();
      }
   }
   return ::remove(arg);
}

object owner() { return (owner); }
string owner_name() { return (owner->query_name()); }

void remove_fun(object player) {
  set_heart_beat(0);
  disable_commands();
}
