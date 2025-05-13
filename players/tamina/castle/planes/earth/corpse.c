#include "/obj/lw.h"
#include "/players/tamina/defs.h"

int counter; 
status arms, legs, torso, head;
object ob;

int id(string arg) 
{
  return arg == "corpse" || arg == "corpse of lord";
}

void long() 
{
  writelw("This is the corpse of the Lord of Earth ");
  if (arms)
    writelw("with the arms cut off, ");
  if (head)
    writelw("with the head cut off, ");
  if (torso)
    writelw("with the torso cut off, ");
  if (legs)
    writelw("with the legs cut off, ");
  writelw("so it looks quit disgusting.\n");
}

void reset(int arg) 
{
  arms = 0;  legs = 0;  torso = 0;  head = 0;
  counter = 4;
  if (arg) return 0;
}

string short()  
{  
  if (counter == 4)
    return "The corpse of the Lord of Earth";
  if (counter == 3)
    return "The decayed corpse of the Lord of Earth";
  if (counter == 2)
    return "The heavily decayed remains of the Lord of Earth";
  if (counter == 1)
    return "The skeleton of the Lord of Earth";
}

int can_put_and_get() { return 1; }

void init() 
{
  add_action("_cut", "cut");
  add_action("_get", "get");
  call_out("do_decay", 10);
}

int _cut(string str) 
{
  object ob;

  if (present("sacrificial knife", TP)) 
  {
    if (counter > 1)
    {
      if (str == "arms from corpse")
      {
        if (!arms) 
        {
	  write("You hack off the arms from the corpse.\n");
  	  say(TPN+" stabs deeply into the corpse and pulls something out.\n");
          ob = clone_object(PLANES + "part");
          ob->set_name("Arms of the Lord of Earth");
	  ob->set_part("arms");
	  ob->set_code("ea2");
	  ob->set_owner("Lord of Earth");
	  ob->set_short("Pair of Arms");
	  ob->set_long("The hacked off arms from the Lord of Earth.\n");
	  ob->set_weight(1);
	  ob->set_value(1);
  	  transfer(ob, TP);
	  arms = 1;
	  return 1;
        }
        write("The arms have already been cut out.\n");
        return 1;
      }
      if (str == "head from corpse")
      {
        if (!head) 
        {
	  write("You hack off the head from the corpse.\n");
	  say(TPN+" stabs deeply into the corpse and pulls something out.\n");
          ob = clone_object(PLANES + "part");
          ob->set_name("Head of the Lord of Earth");
	  ob->set_part("head");
	  ob->set_code("eh1");
	  ob->set_owner("Lord of Earth");
	  ob->set_short("A head");
	  ob->set_long("The hacked off head from the Lord of Earth.\n");
	  ob->set_weight(1);
	  ob->set_value(1);
	  transfer(ob, TP);
	  head = 1;
	  return 1;
        }
        write("The head has already been cut off.\n");
        return 1;
      }
      if (str == "torso from corpse") 
      {
        if (!torso) 
        {
	  write("You hack off the torso from the corpse.\n");
	  say(TPN+" stabs deeply into the corpse and pulls something out.\n");
          ob = clone_object(PLANES + "part");
          ob->set_name("Torso of the Lord of Earth");
	  ob->set_part("torso");
	  ob->set_code("et4");
	  ob->set_owner("Lord of Earth");
	  ob->set_short("A Torso");
	  ob->set_long("The hacked off torso from the Lord of Earth.\n");
	  ob->set_weight(2);
	  ob->set_value(1);
	  transfer(ob, TP);
	  torso = 1;
	  return 1;
        }
        write("The torso has already been cut out.\n");
        return 1;
      }
      if (str == "legs from corpse")
      {
        if (!legs) 
        {
	  write("You hack off the legs from the corpse.\n");
	  say(TPN+" stabs deeply into the corpse and pulls something out.\n");
          ob = clone_object(PLANES + "part");
          ob->set_name("Legs of the Lord of Earth");
	  ob->set_part("legs");
	  ob->set_code("el3");
	  ob->set_owner("Lord of Earth");
	  ob->set_short("Pair of Legs");
	  ob->set_long("The hacked off legs from the Lord of Earth.\n");
	  ob->set_weight(1);
	  ob->set_value(1);
	  transfer(ob, TP);
	  legs = 1;
	  return 1;
        }
        write("The legs have already been cut off.\n");
        return 1;
      }
      write("You cannot cut that.\n");
      return 1;
    }
    write("But the corpse is too decayed to cut anything from it.\n");
    return 1;
  }
  write("You have nothing sharp enough to cut with.\n");
  return 1;
}

monster_died(obj) 
{
  int i, coins;
  object inv, money;

  inv = all_inventory(obj);
  for(i = 0; i < sizeof(inv); i++)
    MO(inv[i], TO);
  coins = obj->query_money();
  money = clone_object("/obj/money");
  money->set_money(coins);
  if (coins) 
    move_object(money, TO);
  move_object(TO, E(obj));
  destruct(obj);
  return 1;
}

int do_decay() 
{
  if (counter == 1)
  {
    write("The remains of the Lord of Earth vanish.\n");
    destruct(TO);
    return 1;
  }
  counter--;
  call_out("do_decay", 20);
  return 1;
}
