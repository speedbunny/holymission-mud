inherit "obj/monster";
#include <lw.h>

int id(string str)
  {return str=="dwarf"||str=="veteran"||str=="dwarven veteran";}

void reset(int arg)
  {object a, w;
  ::reset(arg);
  if(!arg)
    {set_name("dwarven veteran");
    set_race("dwarf");
    set_alt_name("veteran");
    load_chat(10+random(5),({"The dwarves chat with each other.\n",
    "An old dwarf tells you: Yep, In my days we didn't kill dragons with swords,\n"+
    "we used our teeth!\n",
    "A group of fighters laugh and drink ale in the corner.\n"}));
    set_gender(1);
    set_level(14);
    set_wc(14);
    set_ac(14);
    set_hp(450+random(150));
    set_al(100);
    set_chance(0);
    set_whimpy(1);
    set_spell_dam(5);
    set_aggressive(0);
    set_short("A dwarven veteran");
    set_long(lw("Looking more like an oversized prune than a dwarf, the old "+
    "veteran hobbles around the room, telling tales of the old "+
    "days.  Although old, he still looks like a tough cookie.\n"));
    if(random(2)) {a=clone_object("obj/armour");
    a->set_name("dwarven chainmail");
    a->set_alt_name("chain");
    a->set_alias("chainmail");
    a->set_short("Dwarven Chain");
    a->set_long(lw("Dwarven chainmail, while usually small and not as good as plate, "+
    "is still a valuable piece.  Living deep underground, and working "+
    "ore all their lives, the dwarves have become quite skilled at "+
    "creating new alloys and fashioning equipment.\n"));
    a->set_type("armour");
    a->set_size(2);
    a->set_ac(4);
    a->set_value(1000);
    a->set_weight(6);
    transfer(a,this_object());  command("wear chain",this_object());}
    if(random(2))
      {w=clone_object("obj/weapon");
      w->set_name("shortsword");
      w->set_alt_name("dwarven shortsword");
      w->set_class(10);
       w->set_weight(3);
      w->set_short("Dwarven shortsword");
      w->set_long("A dwarven shortsword.\n");
      transfer(w,this_object());
      command("wield shortsword",this_object());}}}


