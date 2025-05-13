inherit "obj/weapon";
#include "/players/meecham/def.h"
reset(arg)
{
  if(arg) return;
  ::reset(arg);
  set_name("scythe");
  set_class(10);
  set_weight(4);
  set_value(20000);
  set_short("Scythe of beheading");
  set_long("This wicked looking scythe has a sharp, curved blade at its tip.\n\
It looks like a rather clumsy weapon, but could seemingly do fatal damage if\n\
used properly.\n");
  set_hit_func(TO);
}
 
magic_hit(ob)
{
  if(!random(10))
  {
    printf("You slice your scythe diagonally across your foe's face!\n");  
    return 50;
  }
  if(!random(10))
  {
    printf("You sweep your scythe in a direct line across your foe's neck!\n");
    printf("The "+ob->query_name()+"'s neck is severed by your devastating blow!\n");
    printf("The lifeless body of the "+ob->query_name()+" falls to the ground.\n");
    return 20000;
  }
}
 
 
