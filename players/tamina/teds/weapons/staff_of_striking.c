inherit "obj/weapon"; 
int charges;

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("Staff of Striking");
  set_alias("staff");
  set_alt_name("staff of striking");
  set_short("An Ironwood Staff");
  set_long(
    "This is a large staff made from a very heavy, sturdy ironwood.\n"+
    "It has coiled around it a long, green snake, with the head sitting\n"+
    "menacingly at the top.\n");
  set_class(8);
  set_type(3);
  set_weight(4);
  set_value(2000);
  set_hit_func(this_object());
  charges = 50 + random(101);
}

int weapon_hit(object attacker) 
{
  if (charges >= 0) 
  {
    charges -= 1;
    tell_object(wielded_by,"The staff jerks in your hand like a striking snake!\n");
    return 5 + random(26);
  }
  write("But it has expended all its energy.....\n"+
	"The staff vaporises into gas which blows away on the wind.\n");
  call_other(this_object(), "drop");
  move_object(this_object(),"/players/tamina/teds/storage");
  return 20;
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
