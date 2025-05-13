inherit "obj/npc";
#include "../walhalla.h"
#include "../prison.h"

reset(arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("court guard");
    set_alt_name("guard");
    set_race("human");

    set_short("court guard");
    set_long("This is a normal courtguard. He has got a special knowledge"+
             "of killing people. And he is going to arrest you...\n");
    set_gender(1);

    load_chat(20,
         ({ "The guard says: You have "+GUARD_ARREST_TIME+" seconds to escape.\n",
            "The guard says: I'll get you, bastard !\n",
            "The guard says: There is no chance to escape.\n",
            "The guard says: Truth will win.\n",
            "The guard yawns.\n",
            "The guard shouts: Hey budies, come over here, let's arrest this mudder.\n"
         }));

    load_a_chat(20,
         ({ "The guard says: You are right, attacking me is the only chance to escape.\n",
            "The guard says: Truth will win.\n",
            "The guard shouts: Help, help me guys.\n",
            "The guard kicks you in your ass.\n",
            "The guard says: Flee if you can.\n",
            "The guard grins evilly.\n",
            "The guard says: I'll get you.\n",
            "The guard says: If you kill me, another one will get you. Give up !\n",
            "The guard grins.\nThe guard says: Commit suicide is a way to escape the prison.\n"
         }));
    set_level(30);
    set_hp(3000);
    set_attacks_change(100);
    set_attacks(3);    

    set_fol_change(100);
    set_rid_change(25);
    set_dodge(10);     

    set_al(0);
    set_aggressive(0);
    add_money(3000);

    set_spell_mess1("");
    set_spell_mess2("ZZZZZZZZZZZZAAAAAAAAAAWWWWWWWWWWWUUUUUUUUUUPPPPP\n"+
                    "The guard used his knowledge....\n");
    set_chance(40);
    set_spell_dam(60);

    CO("cgsword");
    init_command("powerup");

  }
}



init()
{ if(TP->query_player())
    call_out("wait",GUARD_ARREST_TIME,TP);
  ::init();
}

wait(tp)
{ 
 //  if ((tp && environment(tp)==environment() && tp->query_attack()!=TO &&  tp->query_level()<=30) || (tp->query_name()=="Whisky"))
  if ((tp && environment(tp)==environment() && tp->query_attack()!=TO) &&(tp->query_real_name()!="Beardy"))
  { shout("The evil "+TPN+" was sent to Walhalla's prison.\n");
    tell_object(tp,"The guards of Walhalla arrested you.\n" +
                "You have been sent to prison.\n" +
                "have a nice time there....\n");
    switch(random(8))
    { case 0 :  transfer(TP,ROOM + "pris9"); break;
      case 1 :  transfer(TP,ROOM + "pris8"); break;
      case 2 :  transfer(TP,ROOM + "pris15");break;
      case 3 :  transfer(TP,ROOM + "pris20");break;
      case 4 :  transfer(TP,ROOM + "pris24");break;
      case 5 :  transfer(TP,ROOM + "pris19");break;
      case 6 :  transfer(TP,ROOM + "pris26");break;
      case 7 :  transfer(TP,ROOM + "pris27");break;
    }
     return 1;
   }
   else
   { tell_object(tp,"You are lucky, you escaped from the guards.\n");
     return 1;
   }
   return 0;
}
