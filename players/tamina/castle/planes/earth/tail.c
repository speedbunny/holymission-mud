inherit "obj/weapon";

#include "/players/tamina/defs.h"
#define CH 120       /*  Amount of poison -- and 2 mins  */
status in_progress;
int charges;
string c_str;

void reset(int arg)
{
  ::reset(arg);
  if (!arg)
  {
    set_name("Scorpion's Tail");
    set_alias("tail");
    set_short("Scorpion Tail");
    set_class(15);
    set_type(3);
    set_weight(6);
    set_hit_func(TO);
    charges = CH;
  }
}

long()
{
  switch(charges)
  {
    case 0:
      c_str = "There is no poison left in the Tail";
      break;
    case 1 .. 2:
      c_str = "There is a tiny amount of poison left in the Tail";
      break;
    case 3 .. 8:
      c_str = "The Tail is almost empty of poison";
      break;
    case 9 .. 18:
      c_str = "There is a small amount of poison left in the Tail";
      break;
    case 19 .. 29:
      c_str = "The Tail has some poison left in it";
      break;
    case 30 .. 44:
      c_str = "There is a modest amount of poison still in the Tail";
      break;
    case 45 .. 59:
      c_str = "The Tail is slightly less than half-full";
      break;
    case 60 .. 72:
      c_str = "The Tail is half-full";
      break;
    case 73 .. 89:
      c_str = "The Tail can still do some fearful poison damage";
      break;
    case 90 .. 100:
      c_str = "There is a lot of poison in the Tail";
      break;
    case 101 .. 114:
      c_str = "The Tail is almost full of poison";
      break;
    case 115 .. 121:
      c_str = "The Tail is full of poison";
      break;
    default:
      c_str = "The poison in the tail has completely dried up...";
      break;
    return 1;
  }
  write("This is the tail of a Giant Scorpion.  "+
  	"It looks extremely vicious.\nPerhaps you could <pierce> "+
  	"one of your foes...\n"+c_str+".\n");

}

int weapon_hit(object attacker)
{
  write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"+
"\n"+
"     The Scorpion Tail plunges into the flesh of "+attacker->NAME+" !!\n"+
"\n"+
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  say(TPN+"'s Scorpion Tail stabs deeply into "+attacker->NAME+"'s body !!\n");

  return random(15) + 9;
}

int query_charges()
{
  return charges;
}

int query_value()
{
  return 4500 + (2 * query_charges());
}

init()
{
  ::init();
  AA("_pierce", "pierce");
  AA("_query",  "amount");
}

int _pierce(string victim)
{
  object ob;

  if (!query_wielded())
  {
    write("You must be wielding the Scorpion-Tail to use the poison.\n");
    return 1;
  }
  if (!stringp(victim))
    ob = TP->query_attack();
  else
    ob = present(victim, E(TP));
  if (!ob)
  {
    write("There is no such living thing near you !\n");
    return 1;
  }
  if (in_progress)
  {
    write("But the Tail is still in "+ob->NAME+" !!\n");
    return 1;
  }
  if (charges <= 0)
  {
    write("There is no poison left in the tail...\n"+
          "Perhaps more poison will re-generate...\n");
    call_out("reflow", CH * 5);  /*  10 mins  */
    return 1;
  }
  call_out("hurter", 1, ob);
  in_progress = 1;
  return 1;
}

int reflow()
{
  charges = CH;
  TOBJ(ENV,
"The Scorpion Tail twitches violently as you feel poison flow through it.\n");
  return 1;
}

int hurter(object ob)
{
  int hit;

  if (objectp(ob) && living(ob) && E(ob) == E(TP))
  {
    hit = 15 + random(20);
    write("You pierce the skin of "+ob->NAME+" with the Scorpion-Tail !!\n");
    say(TPN+" pierces the skin of "+ob->NAME+" with the Scorpion Tail !!\n");
    TOBJ(ob, TPN+" pierces your skin with "+TP->QPOS+" Scorpion Tail !!\n");

    ob->add_poison(hit);
    ob->hit_player(10);

    charges = charges - hit;
    in_progress = 0;
    return 1;
  }
}

int _query()
{
  if (!TP->query_immortal())
  {
    write("You too inexperienced to find out the exact amount of \n"+
          "poison-charges in the Tail.\n");
    return 1;
  }
  write("Poison left = "+charges+".\n");
  return 1;
}

