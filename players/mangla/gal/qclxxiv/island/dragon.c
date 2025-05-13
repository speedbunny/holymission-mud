#include "/players/qclxxiv/island/ianimal.h"
#define SHOUT(x) gTellstring=x; filter_array(users(),"filter_tell",this_object())
static string gTellstring;
int running; /* how many heartbeats have we been running now? */
int poisoned;
object lasthit; /* who hit us latest */
 
filter_tell(ob) {
    return ob->catch_shout(gTellstring);
}
 
shyness() { return 0; }
predator() { return 1; }
run_method() { return "walk"; }

/* ommit ianimal's id */
id(arg) { return (arg=="dragon"||arg=="islanddragon"||arg=="island dragon"
					||arg=="qpredator"); }

hold(caller,time) {
  return 1;
}

long() {
    write (process_string(long_desc));
	if (poisoned) write(process_string("It looks badly HURT somehow.\n"));
}

reset(arg) {
  object cx, griftail;
        ::reset(arg);
	 if (arg) return;
	 load_chat(20,({
		"Will the Dragon feed itself with you, a tiny little adventurer?\n",
		"The Dragon looks hungry.\n",
        "The Dragon utters terrible cries.\n",
		"You hear a deep rumbling sound coming from the Dragon's stomach....\n"
	  }));
	 load_a_chat(25,({
        "The Dragon spits fire.\n",
        "The Dragon utters terrible cries.\n",
        "The Dragon is sweeping around its tail.\n",
	  }));
    /* load_match(this_object(), ({ "follow",  ({"leaves",}),})); */
	set_name("dragon");
	set_alias("island dragon");
	set_race("dragon");
	set_level(50);
   	set_wc(30);
	set_ac(100);
   	set_hp(100000);
	set_sp(200);
   	set_spell_mess1("Dragon curls it's tail around its opponent's legs.");
   	set_spell_mess2("Dragon curls it's tail around your legs.");
	set_chance(50);
	set_spell_dam(30);
    set_al(-500);
   	set_aggressive(1);
   	set_short("The Island Dragon");
   	set_long( "The Island Dragon, staring at you furiously.\n");
	enable_commands();
	set_living_name("islanddragon");
	set_gender(0);
	set_size(5);
    griftail=clone_object("obj/weapon");
    griftail->set_id("tail");
    griftail->set_class(20);
    griftail->set_weight(4);
    griftail->set_value(5000);
    griftail->set_short("Dragon's tail");
    griftail->set_long("The powerful Dragon's tail. It looks valueable.\n");
    move_object(griftail,this_object());
}

second_life() {
	object corpse, map, medal;
	if (environment() && lasthit)  {
		tell_room(environment(), lasthit->query_name()
				+" killed the Island Dragon!\n" );
      	lasthit->set_quest("island_dragon");
		map = present("qquest_map", lasthit);
		if (map) { map->set_nomore(1); }
		log_file("qmap",lasthit->query_real_name()+" killed dragon "
				+ctime(time())+"\n");
		write_file("/players/qclxxiv/qquest/qmap",lasthit->query_real_name()
				+" killed dragon " +ctime(time())+"\n");
		SHOUT(
"A terrible cry is heard, "+lasthit->query_name()+" killed the Island Dragon!!!\n" );
	}
	corpse = clone_object("/players/qclxxiv/island/idcorpse");
	call_other(corpse, "set_name", name);
	corpse->set_race(race); /* Added by Bonzo */
	corpse->set_weight(weight);
	transfer_all_to(corpse);
	move_object(corpse, environment(this_object()));
	"/players/qclxxiv/leaf4/beach"->set_corpse(corpse);
	medal = clone_object("/players/qclxxiv/qquest/medal");
	/* medal weighs NOTHING */
	move_object(medal,lasthit);
	tell_object(lasthit,
"Qclxxiv immediately sends you the highest decorations of the Leaf from afar.\n"
+"You can always get rid of it (but why would you?) using: destroy medal.\n");
	destruct(this_object());
	return 1;
}

heart_beat() {
	object mail;
	int lower;
	if (present("qfearstone") && running<11) {
		if (running==10) running=15; /* take a break */
		run_away();
		running++;
	}
	else if (running>0) running--;
	if (poisoned) {
		poisoned--;
		if (poisoned==0) {
   			set_wc(25);
			set_ac(100);
   			set_hp(100000);
			set_sp(200);
			set_chance(25);
			set_spell_dam(35);
		}
	}
	else {
   		set_hp(100000);
	}
	lower = 0;
    if (attacker_ob && present(attacker_ob, environment(this_object())) ) {
		mail = present("qdragonmail", attacker_ob);
		if (mail&&mail->query_worn()) {
			lower = 1;
			tell_object( attacker_ob, "Your mail is glowing.\n");
			max_spell_dam /= 2;
			weapon_class /= 2;
		}
	}
	::heart_beat();
	if (lower) {
		max_spell_dam *= 2;
		weapon_class *= 2;
	}
}

run_away() {		   
	object here, bait;
	here = environment();
	::run_away();
	if (here!=environment()) {
		bait = present("qdragonbait");
		if (bait) {
			if (bait->is_poisoned()) {
				poisoned = 250;
   				set_wc(18);
				set_ac(20);
   				set_hp(10000);
				set_sp(50);
				set_chance(15);
				set_spell_dam(20);
			} 
			if (environment()) {
				tell_room(environment(),
				"The dragon eats "+lower_case(bait->short())+".\n");
				if (poisoned) tell_room(environment(),
		"The dragon utters a terrifying cry. RRRRAHHHHHHHRRARRROOOAAARRRAA\n");
			}
			destruct(bait);
		}
	}
}

hit_player(dam) {
	lasthit = this_player();
	return ::hit_player(dam);
}

reduce_hit_point(dam) {
	if (this_player()!=this_object()) lasthit = this_player();
	return ::reduce_hit_point(dam);
}

plan_move() {
	call_out("maybe_move", 10, 0);
}

maybe_move() {
	if (!attacker_ob || !present(attacker_ob)) {
		run_away();
	}
}

fight_what(int i) {
	switch (i) {
    	case 0: return "missed";
    	case 1: return "tickled";
    	case 2: return "grazed";
    	case 3: return "hit";
    	case 4: return "hit";
    	case 5: return "hit";
    	case 6: return "spit fire on";
    	case 7: return "severely hit";
   		case 8: return "spit massive fire on";
   		case 9: return "trampled";
  		case 10: return "did an INSANE amount of damage by trampling";
		default: return "huh?";
	}
}

fight_how(int i) {
	switch (i) {
    	case 0: return "";
    	case 1: return " with the tip of its tail";
    	case 2: return " with its tail";
    	case 3: return " with its left foreleg";
    	case 4: return " hard with its right foreleg";
    	case 5: return " very hard with its tail";
    	case 6: return "";
    	case 7: return " with its tail";
		case 8: return "";
   		case 9: return " into a puddle of blood and body parts";
  		case 10: return "";
		default: return "huh?";
	}
}

