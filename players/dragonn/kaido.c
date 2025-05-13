
  /*

  Kaido The King of Pavi castle.

    By Dragonn (c) 1996

*/
inherit "obj/monster";

#include "/players/dragonn/defs.h"

object flail, armour;

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return;

   set_name("King Kaido");
    set_alt_name("king");
    set_alias("kaido");
    set_race("legionair");
    set_short("Kaido The King of Pavi castle");
    set_level(70);
    set_size(3);
    set_gender(1);
    set_al(-1000);
 set_hp(100);
    set_wc(60);
    set_ac(20);
    set_spell_mess2("Kaido moves quickly around and strikes you.\n");
    set_spell_dam(50);
    set_chance(29);
    set_aggressive(1);
    add_money(23000+random(500));
    load_chat(33,
  ({"Kaido screams 'AAAAAAAAAAAAAAArrrrrrgggggHHHHHHHH !!\n",
 "Kaido asks you 'You fool, don't you know that Im the king?'\n",
    "Kaido grins.\n", }) );
    load_a_chat(20, 
 ({"Kaido yells 'What the hell are you doing here ??'\n",
    "Kaido asks you 'Im bored ....... *Rah Rah*'\n",
  }));
    set_dead_ob(TO);
 /*
  
  MO(flail, TO);
  MO(armour, TO);

  command("wield flail", TO);
  command("wear armour", TO);
*/
}

void long()
{
  write(
"You see Kaido the King of Pavi castle. "+
"His task is to protect Pavi castle citizens from being "+
"attacked by strangers and to uphold the local law. "+
"He looks like an experienced legionair and you feel that should "+
 "not start any trouble here.\n");

}

int query_con() { return 70; }
int query_str() { return 80; }
int query_int() { return 20; }

 
monster_died(ob)
{
shout(capitalize(TP->query_real_name())+" drains last life force from Kaido.\n");
       write("You just slaid Kaido the King of Pavi castle.\n");
       write("Suddenly from nowhere you hear a strange voice:\n");
       write("        I will remember you, brave adventurer !!!\n");
       write("        Next time, you will pay for it !!!!\n");
if(file_size("/players/dragonn/area/kaido/"+TP->query_real_name()+".o")<1){
write_file("/players/dragonn/area/kaido/"+TP->query_real_name()+".o","Yeah, he killed me, damn adventurer.\n");
write_file("/players/dragonn/area/kaido/"+TP->query_real_name()+".o","He killed me at "+ ctime(time())+". But i'll get you.\n");
}
else return 1;                   
}
    

