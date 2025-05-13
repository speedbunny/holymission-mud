inherit "obj/thing";

#include "/players/tamina/defs.h"

int charges;

void reset(int arg)
{
  ::reset(arg);
  if (arg) return 0;

  set_name("Staff of Curing");
  set_alias("staff");
  set_short("A Rosewood Staff");
  set_long("This sturdy staff seems to fit comfortably in your hands.\n"+
           "You feel better after just holding it.\n"+
  	   "But there is more magic in this than you can see...\n"+
	   "Perhaps you should get it identified...\n");
  set_weight(3);
  set_can_get(1);
  charges = 7 + random(5);

}

int id(string str) 
{
 return str == "staff" || str == "staff of curing" || str == "rosewood staff";
}

int query_value() 
{ 
  return 2000 + ((charges + 1)*500); 
}

int query_charges() 
{ 
  return charges; 
}

string query_info()
{
  return "This is a staff of curing. Type 'touch <player>' to heal.\n";
}

void init() 
{
  ::init();
  add_action("do_heal", "touch");
}

int do_heal(string arg) 
{
  object ob;
  ob = present(arg, E(TP));
  if (!arg || !ob) 
  {
    write("Touch who?\n");
    return 1;
  }
  if (charges <= 0) 
  {
    write("The staff shivers, but nothing happens.\n");
    say(TPN+" touches "+CAP(arg)+" with a rosewood staff,\n"+
        "but nothing happens.\n");
    return 1;
  }
  charges -= 1;
  write("You touch "+ob->NAME+" with the staff.\n"+ 
        "A gentle white light briefly surrounds "+ob->QOBJ+", and then fades.\n");
  say(TPN+" touches "+ob->NAME+" with a rosewood staff...\n"+
      CAP(ob->QPRO)+" is surrounded by a gentle white light.\n");

  if (TP->query_alignment() > 250) 
  {
    write("The staff warms in your healing hands.\n");
    ob->heal_self(random(20) + 60);
    TOBJ(ob, "You feel soothed.\n");
    return 1;
  }
  ob->heal_self(random(20) + 30);
  TOBJ(ob, "You feel soothed.\n");
  return 1;
} 
