inherit "obj/npc";
#include "/players/beardy/walhalla/walhalla.h"

reset(arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("hel");
    set_alt_name("god");
    set_race("god");

    set_short("Hel");
    set_long("This is Hel, the mighty godess of Walhalla. She is the\n" +
             "godess of death and yours is sure now\n");
    set_gender(2);
    set_dead_ob(this_object());

    load_chat(10,
         ({"Hel says: I am the godess of death.\nHel grins evilly.\n",
           "Hel says: I'll kill you, if you attack me.\n",
           "Hel says: I am the best fighter of Walhalla.\n",
            "Hel says: Didn't drink much vine, so i am ready for you.\n",
           "Hel says: Come on, wimp !\n"
         }));

    load_a_chat(10,
         ({"Hel says: My sword will end you spiteful live.\n",
           "Hel says: Get ready to join the dead.\n",
           "Hel says: You are an easy opponent.\n",
           "Hel says: What a poor equipment you have.\n",
           "Hel swears #@@*\"*&^$%@@*&! !!!!\n"
         }));
    set_level(70);
    set_hp(17000);
    set_attacks_change(100);
    set_attacks(7);    

    set_al(600);
    set_aggressive(0);
    add_money(6000);

    set_spell_mess1("");
    set_spell_mess2("WHOOOOOOOOOSH !!!!\n" +
                    "That was an attack just for YOU ...");
    set_chance(60);
    set_spell_dam(100);
    CO("asword");
    CO("aamulet"); CO("acloak"); CO("agloves");
    CO("ahelmet"); CO("ashield");
    init_command("powerup");
  }
}

int monster_died(object mob)
{
   object ob;

   ob=find_object("/players/beardy/walhalla/monster/hel");
   if (!this_player()->query_immortal())
   {
   shout(this_player()->query_name()+
   " successfully killed the Mistress of Death, the goddess Hel.\n");
   }

   if (ob)
       destruct(ob);
  return 0;
}
