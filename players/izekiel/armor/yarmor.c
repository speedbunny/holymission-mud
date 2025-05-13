
inherit "obj/armour";
#include "/players/izekiel/defs.h"

reset(arg){
  ::reset(arg);
  if(arg) return;

  set_name("Armor of Yoshimitsu");
  set_alt_name("armor of yoshimitsu");
  set_alias("armor");
  set_short("Armor of Yoshimitsu");
  set_long(
   "An armor crafted of a strange metal which glows a soft blue in the\n"+
   "dark. It looks very foreign, almost as if it were alien in origin.\n"+
   "There is a small 'Y' etched in the front of the armor, over the \n"+
   "breastplate.\n");
  set_value(200);
  set_light(1);
  set_weight(4);
  set_ac(4);
  set_type("armour");
}

int wear_fun(object player)
{
  tell_object(player,"You are enveloped by a soft blue glow.\n");
  say(TPN+" is enveloped by a soft blue glow.\n");
  return 1;
}

int remove_fun(object player)
{
  tell_object(player,"The soft blue glow disappears from around your body.\n");
  say("The soft blue glow around "+TPN+"'s body disappears.\n");
  return 1;
}
