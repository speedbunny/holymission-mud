#include "/players/tamina/defs.h"

inherit "obj/thing";

reset(arg)
{
  ::reset(arg);
  if (arg) return;

  set_name("Scroll of Summoning");
  set_alias("scroll");
  set_short("An Ash Coloured Scroll");
  set_long("You can see many runes written across the folded\n"+
           "parchment, with a prominent word being:\n\n"+
           "               'Summon'\n\n");
  set_weight(1);
  set_value(700);
  set_can_get(1);
}

int id(string str) 
{
 return str == "scroll" || str == "ash scroll" || str == "scroll of summoning" 
         || str == "ash coloured scroll";
}

query_info() 
{
  write("This is a scroll of summoning, type 'summon <monster>'\n");
  return 1;
}

init() 
{
  if (ENV != TP) return 1;
  AA("_read",   "read");
  AA("_summon", "summon");
}

int _read(string arg)
{
  if (!id(arg))
  {
    NFAIL("Read what?\n");
    return 0;
  }
  long();
  say(TPN+" reads "+TP->QPOS+" Ash-Coloured scroll.\n");
  return 1;
}

int _summon(string arg) 
{
 object ob;

  if (!find_living(arg)) 
  {
    write("Nothing happens.\n");
    TRM (E (TP), 
      "The Ash Scroll reverts to dust and blows to the four winds...\n");
    destruct(TO);
    TP->recalc_carry();
    return 1;
  }
  ob = find_living(arg);

  if (ob->query_immortal()) 
  {
    write("No summoning of wizards!\n");
    return 1;
  }
  if (((TP->INT) + (TP->CHR))/2 < 23)
  {
    write("You do not feel that you are mentally powerful enough to \n"+
	  "summon "+CAP(arg)+".\n");
    return 1;
  }
  write("You summon "+CAP(arg)+"!\n");
  TOBJ(ob, "You are summoned!\n");
  say(TPN+" reads an ash colored scroll and "+CAP(arg)+" appears!\n");
  say(CAP(arg)+" appears in a blinding flash of light !!\n");
  TRM(E(TP),
   "The ash scroll turns to dust and blows away.\n");
  
  MO (ob, E(TP));

  if(ob->query_npc()) 
  {
    ob->set_aggressive(1);
    write(CAP(arg)+" is angry at being summoned!\n"+
          CAP(arg)+" takes you by surprise.\n");
    HIT(25);
    ob->attack_object(TP);
  }
  destruct(TO);
  TP->recalc_carry();
  return 1;
}
