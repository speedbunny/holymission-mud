inherit "obj/weapon";
#include "/players/meecham/def.h"
#define MAX_HEAL 2500-TP->query_level()
int total_heal,check_heal,max_heal;
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Sword of healing");
  set_alias("sword");
  set_short("Sword of healing");
  set_long("This is a mystical sword with special healing powers!\n");
  set_class(19);
  set_weight(8);
  set_value(10000);
  set_hit_func(TO());
}
magic_hit()
{
  if(total_heal>MAX_HEAL)
  { 
    write("Your sword runs out of power and turns to dust.\n");
    say(TPN+" looks confused.\n");
    if(wielded_by)
      wielded_by->stop_wielding(TO());
    destruct(TO());
    return 0;
  }
  else
  if(((TP->query_max_hp()*3/4)>(TP->query_hp())) && (random(100)<10))
  {
    check_heal=random(TP->query_level());
    total_heal+=check_heal;
    TP->restore_hit_point(check_heal);
    write("You feel a little better.\n");
    return 0;
  }
  return 0;
}
 
