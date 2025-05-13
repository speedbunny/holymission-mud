inherit "/obj/monster";

#include "/players/skeeve/area.h"
#include "/players/skeeve/code.h"

reset(arg) {
  object ob;
  ::reset(arg);
  if (!arg) {
    set_name("hobgoblin");
    set_alt_name("hobgoblin");
    set_short("A hobgoblin");
    set_race("hobgoblin");
    set_size(2+random(3));
    set_al(200);
    set_level(11+random(5));
    set_sp(0);
    set_wc(5);
    set_ac(0);
    set_aggressive(0);
    set_whimpy(-1);
  }
  WEAPON("hobgoblin_sword",this_object());
  ARMOUR_CONFIG("old ringmail","old_ringmail",this_object());
  ARMOUR_CONFIG("wellingtons","wellingtons",this_object());
  ARMOUR("simple hood","simple_hood",this_object());
  ARMOUR("old shield","old_shield",this_object());
}

config(version) {
  string str;
  int i;
  str = ({"rambling","fat","poor","tanked"});
  i = (stringp(version))? member_array(version,str) : version;
  if (i<0)i=random(sizeof(str));

  set_name(str[i]+" hobgoblin");
  set_short("A "+ str[i]+" hobgoblin");

  str =({"This goblin seems to spit profusely as he rambles on about nothing.\n"
      +"His armor seems to be a matching set. \n",
    "This rather fat goblin seems to be gorging himself\n"
      +"on some on some raw meat. Yeach!\n",
    "This poor fellow is either having a hard day or is suffering\n"
      +"from an excess of liquid libation.\n",
    "This goblin is obviously too tanked to care that his buddy \n"
      +"across from him is making fun of his mother while accidentally\n"
      +"spitting in his face.\n"
  });
  set_long(str[i]);
  set_alt_name("hobgoblin");
  set_alias("goblin");
  return this_object();
}
