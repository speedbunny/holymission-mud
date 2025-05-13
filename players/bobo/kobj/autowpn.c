/*
 *  AUTOMATIC WEAPON (autowpn) -- Yeah!
 *  A generic automatic weapon, a subclass of the genericer WEAPON object.
 *  Clone or specialize it to get M16:s, machine guns, pulse rifles
 *  -- or even non-automatic weapons!
 *  Thomas Padron-McCarthy, padrone@lysator.liu.se
 *  Kelly (Sigi Huber, k3007e1@alijku11.edvz.uni-linz.ac.at)
 *  Done some changes to the file of Padrone
 *  Thanx for your good ideas
 *  This version uses the gender functions in /obj/living.c!
 */

inherit "obj/weapon";

/* AUTOWPN's extra variables */ 
int max_bullets;	/* How many bullets when full? */
int nr_bullets;		/* How many bullets now? */
int max_salvo;		/* Max nr of shots fired each round */
int wc_per_bullet;     	/* Weapon class per shot fired */
string empty_msg;       /* Message given when no 'bullets' are left */
string bullet_name;     /* Name of the bullets */
string bullet_pl_name;  /* Plural of bullets */
string open_rmsg;       /* Message the other players get */
string open_msg;        /* Message give when opening fire on somebody */
string reload_msg;      /* Message given when reloading weapon */
string sound;		/* Sound, "BANG" for example */
/* Note that class_of_weapon applies when the weapon is used as a club! */
status click_done;	/* 1 when wielder has tried to fire empty weapon */
int value_per_bullet;	/* Added to 'value' */
status monster_reload;	/* If true, NPC:s will automatically reload their weapons
			 *  when they are empty, not just at reset.
			 */

reset(arg) {
    ::reset(arg);
    if (!arg) {
	max_bullets = 0;
	nr_bullets = max_bullets;
	max_salvo = 20;
	wc_per_bullet = 1;
        empty_msg="Click!Click!Click! No bullet left!";
        bullet_name="bullet";
        bullet_pl_name="bullets";
        open_rmsg="opens fire on";
        open_msg="You open fire on";
	sound = "BANG";
        reload_msg="pulls back the trigger of";  
	click_done = 0;
	value_per_bullet = 1;
	set_name("uninitialized generic automatic weapon");
	set_weight(10);		/* Initialized as very heavy */
	monster_reload = 0;
    }
    else if (nr_bullets == 0 && click_done && wielded_by && wielded_by->query_npc()) {
	/* Wielded by a monster: reload! */
	do_monster_reload();
    }
} /* reset */

long() {
    ::long();
    /* Special for AUTOWPN: */
    if (nr_bullets == 0)
	write("There is no "+bullet_name+" left.\n");
    else if (nr_bullets == 1)
	write("There is only one "+bullet_name+" left.\n");
    else
	write("There are "+nr_bullets+" "+bullet_pl_name+" left in it.\n");
} /* long */

init() {
    ::init();
    add_action("wield"); add_verb("wield");
    add_action("do_reload_command"); add_verb("reload");
}

do_reload_command(str)
{
    if (!id(str))
	return 0;
    if (environment() != this_player()) {
	write("You must get it first!\n");
	return 1;
    }
    write("You are not allowed to reload this weapon!\n");
    return 1;
} /* do_reload_command */

do_monster_reload() {
    string printstring;
    printstring = wielded_by->query_name() +" "+reload_msg+" "+
	wielded_by->query_possessive() + " " + name_of_weapon + ".\n";
    write(printstring);
    say(printstring);
    nr_bullets = max_bullets;
    click_done = 0;
} /* do_monster_reload */

id(str) {
    return str == name_of_weapon || str == alt_name || str == alias_name;
}

/* Here is the most important part of the AUTOWPN code: */
/* Note that we have to compensate for class_of_weapon if not used as club. */
hit(attacker)
{
    int nr_fired, i;
    string ratata;
    int wc;

    if (nr_bullets == 0) {
	if (click_done) {
	    if (monster_reload && wielded_by->query_npc()) {
		/* Wielded by a monster: reload! */
		do_monster_reload();
		wc = -class_of_weapon; /* Compensate! */
	    }
	    else {
		tell_object(wielded_by,"You swing your " + name_of_weapon +
		   " and try to smash " + attacker->query_name() + ".\n");
		say(this_player()->query_name() +
		    " swings " + this_player()->query_possessive() +
		    " empty " + name_of_weapon + " and tries to smash " +
		    attacker->query_name() + ".\n");
		wc = 0;	/* Used as club, use class_of_weapon! */
	    }
	}
	else {
    tell_object(wielded_by,empty_msg+"\n");
	    say(wielded_by->query_name() +
		" "+reload_msg+" "  + this_player()->query_possessive() +
		" " + name_of_weapon +
		", but nothing happens.\n");
	    click_done = 1;
	    wc = -class_of_weapon; /* Compensate! */
	}
    }
    else {
	tell_object(wielded_by, open_msg+" "+ attacker->query_name() + ".\n");
	say(this_player()->query_name() + " "+open_rmsg+" " +
	    attacker->query_name()+".\n");

	if (nr_bullets < max_salvo)
	    nr_fired = random(nr_bullets) + 1;
	else
	    nr_fired = random(max_salvo) + 1;
	nr_bullets = nr_bullets - nr_fired;
	ratata = sound;
	i = nr_fired - 1;
	while (i > 0) {
	    i = i - 1;
	    ratata = ratata + "-" + sound;
	}
	ratata = ratata + "!\n";
	say(ratata);
	write(ratata);
	wc = wc_per_bullet * nr_fired - class_of_weapon; /* Compensate! */
    }

    if (hit_func)
	return wc + hit_func->weapon_hit(attacker);
    else
	return wc;
} /* hit -- heavily modified for AUTOWPN */

query_value() {
    return value + nr_bullets * value_per_bullet;
}

/* Use these functions to set AUTOWPN's extra variables: */ 
set_max_bullets(n) { max_bullets = n; }
set_bullets(n) { nr_bullets = n; }
set_max_salvo(n) { max_salvo = n; }
set_wc_per_bullet(n) { wc_per_bullet = n; }
set_sound(s) { sound = s; }
set_value_per_bullet(n) { value_per_bullet = n; }
set_monster_reload(s) { monster_reload = s; }
set_open_msg(s) { open_msg=s; }
set_open_rmsg(s) { open_rmsg=s; }
set_reload_msg(s) { reload_msg=s; }
set_empty_msg(s) { empty_msg=s; }
set_bullet_name(s) { bullet_name=s;  bullet_pl_name=bullet_name+"s"; }
set_bullet_pl_name(s) { bullet_pl_name=s; }
