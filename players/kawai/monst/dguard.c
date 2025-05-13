inherit "obj/monster";
#include <lw.h>

int busy;

void reset(int arg)
  {object a, w;
  ::reset(arg);
  if(!arg)
    {set_level(17);
    set_hp(1200);
    set_name("guard");
    set_race("dwarf");
    set_alt_name("dwarf");
    set_gender(1);
    set_alias("dwarven guard");
    set_al(10);
    set_short("Dwarven Guard");
    set_long(lw("This is a member of the respected Dwarven Legions.  While\n"+
    "normally peaceful creatures, the dwarves enjoy a good fight.\n"));
    set_wc(18);
    set_ac(16);
    set_size(2);
    set_aggressive(0); 
    set_whimpy(-1);
    a=clone_object("obj/armour");
    a->set_name("dwarven plate");
    a->set_alt_name("dwarven plate");
    a->set_alias("plate");
    a->set_short("Dwarven plate");
    a->set_long(lw("Dwarven plate, while usually small, is perhaps one of the "+
    "best armours around.  Living deep underground, and working "+
    "ore all their lives, the dwarves have become quite skilled at "+
    "creating new alloys and fashioning equipment.\n"));
    a->set_type("armour");
    a->set_size(2);
    a->set_ac(5); 
    a->set_value(1200);
    a->set_weight(6);
    w=clone_object("obj/weapon");
    w->set_name("a dwarven broadsword");
    w->set_value(1600);
    w->set_alt_name("dwarven broadsword");
    w->set_class(12);
    w->set_alias("broadsword");
    w->set_weight(3);
    w->set_short("Dwarven broadsword");
    w->set_long(lw("A dwarven broadsword\n "+
    "Living deep underground, and working ore all their lives, "+
    "the dwarves have become quite skilled at creating new "+
    "alloys and fashioning equipment.\n"));
    transfer(a,this_object()); 
    transfer(w,this_object());
    command("wield broadsword",this_object());
    command("wear plate",this_object());}}


void catch_tell(string arg)
  {object who;
  int i;
  string w,x;
  if(busy)
    {return;}
  if(sscanf(arg,"%sking%s",w,x)==2)
    {busy=1;
    who=this_player();
    i=random(5)+1;
    switch(i)
      {case 1: tell_object(who,
        lw("Guard tells you:He's a good king, and I pledge "+
        "my allegiance to him!\n"));
         break;
      case 2: tell_object(who,"Guard tells you: Get lost!\n");
         break;
      case 3: tell_object(who,
         lw("Guard tells you: Ask the farmer at the south "+
         "of Central St.\n"));
         break;
      case 4: tell_object(who,
         lw("Guard tells you: Ask the alchemist at the south "+
         "of Central St.\n"));
         break;
      case 5: tell_object(who,
         lw("Guard tells you: You might want to check out the "+
         "bar in the southeast of town.\n")); 
         break;}
    busy=0;
    return;}
  busy=0;}


