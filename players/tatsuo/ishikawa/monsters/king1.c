/*coded by tatsuo for ishikawa*/

/* serpent */

inherit "/obj/monster";
#include "/players/tatsuo/def.h"
object claw, mail, sta, id, crown;

void reset(int flag) 
{
    ::reset(flag);

    if(flag == 0) 
    {

        set_name("kyoshi");
	set_alt_name("king");
	set_short("The Mighty Serpent King");
	set_race("dragon");
	set_long("The Mighty Serpent King Kyoshi; Ruler of the Shou-Ti clan of\n"+
	  "Serpents. It is covered with green and gold scales which glow with there\n"+
	  "own inner light. Two columns of green smoke drift up from\n"+
	  "its nostrils. From its teeth you can tell it is not to\n"+
	  "be messed with or bothered.\n"+
	  "BEWARE!!!!!!!!\n");
	set_level(50);
	set_gender(1);
        set_hp(13000);
        set_prevent_poison(1);
        add_money(20000+random(30000));
       set_wc(50);
        set_ep(10000);
	set_dead_ob(this_object());
	claw=clone_object("players/tatsuo/ishikawa/obj/serpentclaw");
	mail=clone_object("players/tatsuo/ishikawa/obj/serpentmail");
       crown=clone_object("players/tatsuo/ishikawa/obj/crown");
	move_object(claw,this_object());
	move_object(mail,this_object());
        move_object(crown,this_object());
	init_command("wear mail");
	set_aggressive(1);
	set_chance(40);
	set_spell_mess1("The serpent blasts you with it's golden fire");
	set_spell_mess2("The serpent's golden fire burns you badly, you're toast!!");
        set_spell_dam(40+random(30));

    }
}
void init(){
    ::init();

    add_action("no_hold", "hold");
    add_action("no_hold", "crush");
    add_action("no_hold","timehold");
    add_action("no_hold","freeze");
    add_action("no_ass","backstab");
    add_action("no_ass","assassination");
    add_action("no_throw","throw");
    add_action("no_throw","berzerk");
    add_action("no_throw","suggest");
   add_action("no_throw","fear");
    add_action("no_throw","but");
}

no_ass(){
    write("You fool no one can sneak up on the mighty KYOSHI!!!!\n");
    say(TPN+ "foolishly tries to sneak up on KYOSHI!\n");
    return 1;
}

no_hold(){
int chance;
chance=random(100)+1;
if(chance<50){
write("Kyoshi resists your puny magic.\n");
say("Kyoshi resists "+TP->query_name()+"'s attempt to cast a spell on him.\n");
return 1;
}
else return 0;
}

no_throw(){
    write("KYOSHI effortlessly evades your attack.\n");
    say(TPN+ "attack is easily avoided by Kyoshi.\n");
    return 1;
}

/* returns 0 if the monster dies: 1 if not */

int monster_died(object obj) 
{
    object _star, _pl, _id;
    closure call;   /* direct addressator */

    call = #'call_other; 
    _pl = this_player();
    _star = present("star",_pl);
    _id = present("serpent_id",_pl);

    if (apply(call,_pl,"query_immortal"))
        return 0;
    else 
       shout(apply(call,_pl,"query_name")+" killed the evil Serpent King.\n");

// we check the filename too, because there can me other things called star

    if(_star && 
      explode(file_name(_star),"#")[0] == "players/tatsuo/ishikawa/obj/star") 
      return 0;
    else 
    {
       _star = clone_object("players/tatsuo/ishikawa/obj/star");
       if (transfer(_star, _pl))  /* too much weight */
          move_object(_star, environment(_pl));
       write("A Gold Star magically appears.\n");
    }

   if (_id)
       return 0;
   else 
   {      
       _id= clone_object("/players/tatsuo/ishikawa/obj/serpent_id");
       if (transfer(_id, _pl))
          move_object(_star, environment(_pl));
   }
  return 0;
}

/*endif*/
hit_player(dam,kind)  /* poisons only when it got a hit */
{
    if (random(100) < 8 && dam > 0)
    {
	tell_room(environment(),
	  "Serpent King claws "+attacker_ob->query_name()+".\n");
	this_player()->add_poison(30 + random(8));
	this_player()->hit_player(10 + random(40)); /* for the claws */
    }
    return ::hit_player(dam,kind);
}

int attack() 
{
    int i, sz;
    object *inv;

    if(::attack() && !random(15))
    {
	if(attacker_ob && living(attacker_ob))
	{
	    inv = all_inventory(attacker_ob);

	    for(sz = sizeof(inv), i=0; i < sz; i++)
	    {
		if (inv[i]->query_wielded())   /* a wielded weapon */
		{
		    tell_object(attacker_ob,
		      "The serpent grabs your weapon with it's jaw!! "+
		      "YOU ARE NOW WEAPONLESS!!!\n");
		    attacker_ob->stop_wielding(inv[i]); /* don't destruct :*) */
		    move_object(inv[i],this_object());
		    say("The serpent grabs "+attacker_ob->query_name()+
                      " weapon in it's jaw! HE IS WEAPONLESS NOW !!\n",attacker_ob);
		    return 1;
		} /* endif */
	    } /* endfor */
	}   /* endif */
	return 1;   /* (success) */
    }  /* endif */
    return 0;
}

