inherit "obj/weapon";
#include "/players/meecham/def.h"
int i;
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Sword of good");
  set_alias("sword");
  set_short("Sword of good");
  set_long("Evil monsters cringe at the mere sight of this glorious blade!\n");
  set_class(19);
  set_weight(9);
  set_value(10000);
  set_hit_func(TO());
}
magic_hit(arg)
{
  if(arg->query_alignment()<=(-200))
  {
    if(random(100)<10)
    {
      write("You sword shows its fury at the sins of your foe!\n");
      say(TPN+" shoves his sword into the "+TP->query_attack()->query_name()+
          "and blue fire enters its body!\n");
      return 50;
    }
    return 0;
  }
  if(arg->query_alignment()>=200)
  {
    i++;
    if(i<5)
    {
      write("Your feel revulsion from your sword.\n");
      return 5;
    }
    else
    {
      write("Your sword refuses to fight any longer.\n");
      if(wielded_by)
        wielded_by->stop_wielding(TO());
      destruct(TO());
      say(TPN+" looks confused.\n");
      return 0;
    }
  }
  return 0;
}
 
 
  
 
