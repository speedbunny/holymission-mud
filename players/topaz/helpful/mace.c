inherit "obj/weapon";
#include "/players/meecham/def.h"
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("death mace");
  set_alt_name("club");
  set_alias("mace");
  set_class(1);
  set_value(50000);
  set_hit_func(this_object());
  set_short("death mace");
  set_long("This is Coldrik's Death mace, rumoured to have been forged"+
"by the Gods themselves.  Unlike an ordinary mace, it has three spiked balls"+
"hanging from its end.  The white ball of good glows with purity.  The red"+
"ball of neutrality hangs between the other two.  The black ball of evil"+
"has no glow but gives the illusion of radiating power.\n");
}
 
weapon_hit(arg)
{
  int rnd_hit,rnd_dam,rnd_poison;
  rnd_hit=random(10);
  switch(rnd_hit)
  {
    case 0:
      write("\The white ball glows brilliantly!  You can sense strength draining\n\
from your opponent and being transferred to you.\n");
      say("The white ball on "+TPN+"'s mace glows brilliantly!\n");
      rnd_dam=35+random(16);
      TP->restore_hit_points(rnd_dam);
      return (rnd_dam);
      break;
 
    case 1:
      write("The red ball swings with blinding speed getting in two hits!\n");
      say(TPN+" gets in two hits!\n");
      rnd_dam=40+random(11);
      printf("You did an INSANE amount of damage to %s.\n",arg->query_name());
      tell_object(arg,TPN+" did an INSANE amount of damage to you.\n");
      arg->hit_player(rnd_dam);
      return (rnd_dam);
      break;
 
    case 2:
      write("The black ball oozes goo as it scrapes "+arg->query_name()+
        ".\n");
      say("The black ball seeps fluids as it strikes "+arg->query_name()+
        ".\n");
      if(TPR !="coldrik")
        rnd_poison=random(TP->query_str());
      else
        rnd_poison=random(30);
      if(TPR !="meecham")
      arg->add_poison(rnd_poison);
      return 0;
      break;
  }
  return 0;
}
 
