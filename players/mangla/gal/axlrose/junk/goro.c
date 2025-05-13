/* Goro's Lair */
inherit "obj/monster";
#define AO attacker_ob

void reset(int flag) 
{
    ::reset(flag);
    if(flag == 0) 
    { 
	set_name("goro");
	set_alias("monster");
	set_short("Goro");
	set_long("This is Goro. He is a mountain of immovable muscles\n" 
	+"with hideous features. Four arms protude from his sides,\n" 
	+"two on each side and he has a vaguely humanoid face. You\n" 
	+"feel your gut wrench as you face such a formidable opponent.\n"  
	+"He grins evily and immediately lunges at you.\n");
	set_gender(1);
	set_race("monster");
	set_level(40 + random(20) );
	add_money(5000);
	set_wc(35);
	set_ac(13);
	set_aggressive(1);
	set_al(-2000);
    }
}

heart_beat()
{
    ::heart_beat();
    if(AO && present(AO, environment()) ) 
    {
	if(!random(3)) 
	{
	    tell_object(AO,"Goro grabs you and pounds your chest before\n" 
	    +"throwing you down !\n");
	    say("Goro grabs "+AO->query_name()+" and pounds "+this_player()->query_objective()+"\n"
	      "with his huge fists before finally dropping "+this_player()->query_objective()+".\n", AO);
	    AO->hit_player(75);
	}
	else if (!random(6)) 
	{
	    tell_object(AO,"Goro unleashes a fireball out of its mouth\n" 
	    +"that pulverizes you !\n");
	    say("Goro unleashes a fireball at "+AO->query_name()+" which\n"
		+"pulverizes "+this_player()->query_objective()+" !\n",AO);
	    AO->hit_player(100);
	}
    }
}
