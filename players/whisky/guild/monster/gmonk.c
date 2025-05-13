

/* -----------------------------------------------------------------
   filename: gmonk.c last edit: 2.1.94 whisky uni-linz.ac.at
   changes: because its a guild guard and no monster to slay for
	    just exp :*)
   ----------------------------------------------------------------- */

#define SAY(x) tell_room(environment(),x)
inherit "/obj/monster";

static int aik;   /* for aikido */
object shad;
static object last_attacker;    /* just to avoid bugs */

reset(a) 
{
    ::reset(a);
    if (a) return 0;
    aik = 0;
    set_name("bruce lee");
    set_alt_name("bruce");
    set_short("Bruce Lee");
    set_long("Bruce Lee the Guildmaster of the blue-order.\n"+
      "You see a brown-haired, green-eyed monk, with\n"+
      "a strong athletic body. He looks like he is ready\n"+
      "to protect his guild from non-guildmembers.\n");
    set_gender(1);
    set_race("gnome");
    set_level(90);
    set_hp(5000);
    set_dead_ob(this_object());
    add_money(10000+random(5000));
    shad = clone_object("/players/whisky/guild/shadows/blink_shad");
    shad->start_shadow(this_object(),0,"blink",0);
    shad = clone_object("/obj/shadows/resist_fire_shad");
    shad->start_shadow(this_object(),"resist_fire",0);
    shad = clone_object("/obj/shadows/resist_cold_shad");
    shad->start_shadow(this_object(),"resist_cold",0);
}

attack()
{
    int check;
    if (!aik) 
    {
	SAY("Bruce Lee conzentrates on aikido !\n");
	set_n_ac(query_n_ac()+19);
	set_n_wc(query_n_wc()+28);
	aik = 1;
    }

    if (objectp(attacker_ob))
    {
	if (attacker_ob->query_ghost())
	{
	    last_attacker = 0;
	} else {
	    last_attacker = attacker_ob;
	}
	if (attacker_ob && environment(attacker_ob) == environment())
	{
	    switch(random(100))
	    {
	    case 0..40:  do_feet(attacker_ob);
		return ::attack();
	    case 41..50: do_choke(attacker_ob); 
		return ::attack();
	    default:
		if (!random(4))
		{
		    if (check <= 2) 
		    {
			this_object()->attack();
			check++;
		    } else {
			check = 0;
		    }
		}
		return ::attack();
	    }
	}
	return ::attack();
    }
}

do_feet(object ob)
{
    string pwhat, mwhat;

    switch(random(4))
    {
    case 0: pwhat = "body"; mwhat = "his right foot";
    case 1: pwhat = "head"; mwhat = "his right foot";
    case 2: pwhat = "body"; mwhat = "his left foot";
    case 3: pwhat = "head"; mwhat = "his left foot";
    }

    if (ob) 
    {
	ob->hit_player(20+random(50));
	SAY("Bruce Lee hits the "+pwhat+" of "+ob->query_name()+" with "+mwhat+".\n");
    }
}

do_choke(object ob)
{
   int x;

    if (ob)
    {
	    ob->hit_player(20+random(120));
       x =  1 + random(5);
       
       if (x && ob->hold(this_player(),x)) 
           disable_interactive(ob,x);
	    SAY("Bruce Lee holds down "+ob->query_name()+
           "'s head and raises his knee.\n"); 
    }
}

hit_player(int dam,int kind)
{
    if (dam < 400)    return ::hit_player(dam,kind);
    else if (kind == 5 || kind == 7) return ::hit_player(dam/2,kind);
    else {
	SAY("Bruce Lee makes move and dodges "+attacker_ob->short()+
	  " 's lame attack.\n"); 
    }
    return 0;
}

init()
{
    /*
    if (last_attacker && environment(last_attacker) == environment())
       attack_object(last_attacker);
     */
    ::init();
}
query_property()
{
    return "no_clean_up";
}
int monster_died(object ob)
{
    return 0;
}

int query_dex()
{
    return 150;
}

int query_str()
{
    return 150;
}

int detect_invis()
{
    return 1;
}
