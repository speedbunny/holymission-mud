inherit "obj/weapon";
#include "/players/meecham/def.h"
query_auto_load() { return "/players/meecham/weapons/death_dagger.c:"; }
object attacker;
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("death dagger");
  set_alias("dagger");
  set_short("Death dagger");
  set_long("This is the dreaded Death Dagger which can only be wielded by\n"+
    "the best of thieves.\n");
  set_class(20);
  set_weight(7);
  set_value(0);
  set_hit_func(TO());
}
 
magic_hit(arg)
{
  if(random(100)<30)
  {
    attacker=arg;
    arg->stop_fight();
    TP->stop_fight();
    attacker->stop_hunter(0);
    write("Suddenly your dagger blazes to life!\n");
    say(capitalize(TPR)+"'s dagger blazes to life!\n");
    return 0;
  }
  call_out("msg_1",2);
  return 1; /* ??? */
}
 
msg_1()
{
  write("\nYour dagger spins you around...\n");
  say(capitalize(TPR)+"'s dagger spins "+TP->query_possessive()+" around...\n");
  call_out("msg_2",4);
}
 
msg_2()
{
  tell_room(env(TP),"\n\n\n\n\nand around...\n"); /* ??? */
  call_out("msg_3",3);
}
 
msg_3()
{
  tell_room(env(TP),"\n\n\n\n\nfaster...\n");
  call_out("msg_4",2);
}

msg_4()
{
  tell_room(env(TP),"\n\n\n\n\nand faster...\n");
  call_out("msg_5",1);
}
 
msg_5()
{
  tell_room(env(TP),"\n\n\n\n\nUNTIL...\n");
  call_out("death",2);
}
 
death()
{
  tell_room(env(TP),"\n\n\n\n\nP O W !!!\n");
  attacker->hit_player(20000);
  return 1;
}
