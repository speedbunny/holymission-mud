#include "/players/tamina/defs.h"

object e,kill_ob;
int hp,i,r;
int or;			/* Number of heartbeats */
string KON,KOPOS;
string msg1,msg2;

id(str) { return str == "lava"; }

query_name () { return "lava"; }

short () { return "River of Lava"; }

alias() { return "hot lava"; }

long() { 
  write("The Lava oozes all over you, searing you, burning you!!!\n");
}

query_pronoun() { return "it"; }

query_npc() { return 1; }


init() { 
  enable_commands(); 
}

burn_player(ob) 
{
  if (ob->query_wizard() && ob->query_invis()) 
  {
     destruct(TO);
     return;
  }
  kill_ob = ob;
  KON = ob->NAME;
  KOPOS = ob->QPOS;
  ob->attack_object(TO);
  set_heart_beat(1);
}

heart_beat() 
{
  if (!kill_ob || kill_ob->query_ghost() || E(kill_ob) != E(TO)) 
  {
     destruct(TO);
     return;
  }
  
  r = random(5) + 1;
  for(i = 0; i < r; i++) 
  {
   msg1="";
   msg2="";
   switch(random(5)) 
    {
    case 0: msg1+="Flames lick up from your shoes to your hair !";
	    msg2+="Flames lick up from "+KON+"'s shoes to "+KOPOS+" hair !";
		break;
    case 1: msg1+="The heat of the oven takes your breath away !";
	    msg2+=KON+" desperately tries to breathe, but\n"
		+ "only smoke gets in "+KOPOS+" nostrils !"; 
		break;
    case 2: msg1+="You feel like Satan has come to visit you !";
	    msg2+="Satan has come to visit "+KON+" !";
		break;
    case 3: msg1+="You feel your left eyeball burst into flames "
		+"as it burns your head !";
	    msg2+=KON+" screems with horror as "+KOPOS+" left eyeball "
		+"bursts\nlike a toad being blown up !";
		break;
    case 4: msg1+="Blisters appear on your back, as the flames lick\n"
		+"slowly around your body !";
	    msg2+="Blisters appear on "+KON+"'s back, as the flames\n"
		+"lick slowly  "+KON+"'s body !";
		break;
    }
    msg1+="\n";
    msg2+="\n";
    TOBJ(kill_ob, msg1);
  }
  hp = kill_ob->HP/2;

  if (hp < 100) hp = 25 + random(TP->HP*2);

  kill_ob->hit_player(hp);

  if (++or==3 && !kill_ob->query_ghost()) 
  {   
     TOBJ(kill_ob,"\nYou manage to struggle out of the river of lava.\n\n");
     kill_ob->set_alignment("burning");
     MO(kill_ob, FIRE + "rm4");
     TRM(FIRE + "rm4", KON+" arrives, coughing and smoking, still burning a bit !\n",kill_ob);
     command("look", kill_ob);
     destruct(TO);
     return;
   } 

}

add_exp(i) 
{
  string name;
  object *ob,th;

  ob = all_inventory(kill_ob);

  for (i = 0; i < sizeof(ob); i++)
    if (!random(3) && (name = ob[i]->NAME) && !ob[i]->drop())
     {
	th = CLO("obj/thing");
	th->set_name(name);
	th->set_short(ob[i]->short()+" (burning)");
	th->set_weight(1);
        th->set_value(40);
	th->set_can_get(1);
	MO(th, FIRE + "rm4");
	destruct(ob[i]);
    }
}
