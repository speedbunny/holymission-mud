inherit "obj/weapon"; 
#define WB wielded_by
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
  set_weight(4);
  set_value(3000);
  set_hit_func(this_object());
  charges = 50 + random(101);
}

TA(str)
{
  write(str);
  say(str);
}

int weapon_hit(object attacker) 
{
  string AN;
  AN = attacker->query_name();

  if (charges >= 0) 
  {
    switch(random(4))
    {
      case 0:
        TA("The Staff jerks in your hand like a striking snake!\n");
        charges -= 1;
        return 5 + random(11);
      break;
      case 1:
        TA("The Staff strikes violently at "+AN+"!!\n");
        charges -= 1;
        return 5 + random(16);
      break;
      case 2:
        TA("The Striking Staff pummels into "+AN+" !!!\n");
        charges -= 1;
        return 5 + random(21);
      break;
      case 3:
        TA("The Striking Staff glows with brilliance as "+AN+" is squashed to a pulp.\n");
        charges -= 1;
        return 5 + random(26);
      break;
    }
  }
  write("But the Striking Staff has expended all its energy.....\n"+
	"The staff vaporises into gas which blows away on the wind.\n");
  call_other(this_object(), "drop");
  destruct(this_object());
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

int query_charges()
{
  return charges;
}


