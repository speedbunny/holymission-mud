inherit "obj/monster";
#include <lw.h>

#define TP this_player()
#define TPN TP->query_real_name()

static object x;

void reset(int arg)
  {object a;
  ::reset(arg);
  if(!arg)
    {set_level(80);
    set_hp(8000);
    set_race("demi-god");
    set_name("kazak");
    set_alt_name("kq1-god");
    set_al(-500);
    set_gender(1);
    set_chance(80);
    set_spell_dam(40+random(10));
    set_spell_mess1("Kazak knocks you across the room with a mighty backhand.");
    set_spell_mess2("Kazak strikes you down with a bolt of lightning.");
    set_short("Kazak the demi-god");
    set_long(lw("Kazak is a hideous creature, standing 12 feet tall and weighing "+
    "several tons.  It's arms are massive, all 4 of them, and it looks "+
    "capable of crushing you without much effort.  As it stands ready "+
    "to destroy the world, it picks up a bowing cult member and munches "+
    "off its head.\n"));
    load_a_chat(20,({"Kazak crushes you with his foot.\n",
    "Kazak screams: Fools!  I shall destroy them all!\n",
    "Kazak laughs hideously!\n"}));
    set_wc(25);
    set_ac(20);
    set_size(5);
    set_aggressive(1);
    set_whimpy(-1);
    set_dead_ob(this_object());
    add_money(7500);}}

varargs mixed hit_player(int dam,int kind,mixed elem)
  {object ob;
  x = this_object()->query_attack();
  if(ob=present("kq1-sword",this_player()))
    {if(ob->query_wielded())
      {return ::hit_player(1000);}}
  return ::hit_player(0,kind,elem);}


void monster_died(object ob)
  {object y,z;
  if(x->query_immortal())
    {write("DEBUG: Quest done!\n");
    return;}
  shout("Demi-god Kazak shouts: I shall return, " +
  capitalize(x->query_name())+", to destroy you "+
  "and the rest of your pathetic world!\n");
  if(y=present("kq1-list",x))
    {destruct(y);}
  tell_object(x,"You killed the evil demi-god Kazak!\n");
  if(x->query_quests("kill_cult")) 
    {return;}
  else
    {this_player()->set_quest("kill_cult");
    write_file("/players/kawai/log/quest",x->query_name()+
    " solved the quest on "+ctime(time())+"\n");}
  return;}

