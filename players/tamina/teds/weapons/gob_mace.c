inherit "obj/weapon"; 
int charges;

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("goblin king's mace");
  set_alias("mace");
  set_short("Goblin King's Mace");
  set_long(
    "This is the Mace once wielded by the fiersome Goblin King.\n"+
    "It appears to be some sort of well-crafted, magical weapon...\n");
  set_class(12);
  set_type(3);
  set_weight(3);
  set_value(2500);
  set_hit_func(this_object());
  charges = 50 + random(101);
}

int weapon_hit(object attacker) 
{

  if (!random(4))
  {
    if (charges >= 0) 
    {
      charges -= 1;
      write("The Mace bludgeons "+attacker->query_name()+" to a pulp!!\n");
      tell_object(attacker, "You are bludgeoned by "+wielded_by->query_name()+"'s Mace !!\n");
      return 5 + random(16);
    }
    write("But it has expended all its energy.....\n"+
  	  "The mace vaporises into gas which blows away on the wind.\n");
    destruct(this_object());
    return 20;
  }
  else 
  return 3;
}

int query_charges()
{
  return charges;
}

void init()
{
  ::init();
  add_action("_query", "charges");
}

int _query()
{
  if (!this_player()->query_immortal())
    return 0;
  write("Charges remaining = "+charges+"\n");
  return 1;
}
