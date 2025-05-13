/*Baal-Rog 
  Created by Airborne  */

inherit "obj/monster"; 

object axe,bad,gem;

reset(arg) {
    ::reset(arg);
    if (arg) return 1;
    set_name("baal-rog");
    set_short("Baal-Rog the Demon Lord");
    set_long("The Baal-Rog, prince of Demons.\n"+
      "It towers over you in a awesome pose. The blood dripping from\n"+      
      "its open maw reeks of pain. Somehow you know that its last meal\n"+
      "did not die a pleasant death. And you are most certain that neither\n"+
      "will you!\n");
    set_race("demon");
    set_alias("baalrog");
    set_alt_name("lord");
    add_money(3000+random(5000));
    set_aggressive(1);
    set_level(20);
    set_hp(50);
    set_no_ears(1);
    set_size(5);
    set_weight(100);
    set_gender(1);
    set_dead_ob(this_object());
    load_a_chat(40,({"The Baal-Rog crushes you with his massive claws!\n"+
	"The Baal-Rog burns you with his deadly breath.\n"+
	"The Baal-Rog makes you feel his evilness!\n",""}));
    axe=clone_object("players/airborne/weapons/hellfire");
    gem=clone_object("players/airborne/obj/gem");
    move_object(axe,this_object());
    move_object(gem,this_object());
    init_command("wield axe");
    set_wc(50);
}
monster_died(ob) {
    if(this_player()->query_immortal()) return;
    shout(this_player()->query_name()+" killed the Baal-Rog.\n");
    bad = clone_object("players/airborne/obj/badge");
    transfer(bad, this_player());
    write("A badge mystically finds its way to you.\n");
    return 0; 
}
attack() {
    object ob,rog;
    int i;
    rog=this_object();

    if (::attack()) {
	if (random(100) < 4) {
	    ob=all_inventory(environment(rog));
	    for(i=0;i<sizeof(ob);i++) {
		if (living(ob[i]) && (ob[i]!=rog)) {
		      ob[i]->hit_player(120+random(80));
		      tell_room(environment(rog)," Baal-Rog breathes hellfire into the area !\n");
		  }
	      }
	    }
	    return 1;
	}
	return 0;
    }

    hit_player(dam) {
	if (random(100) < 6) {
	    tell_room(environment(),"Baal-Rog knocks "+this_player()->query_name()+                               "'s attack aside with great ease!\n");
	    return;
	}  
	else if (random(100) < 12) {
	    tell_room(environment(),"Baal-Rog parries "+this_player()->query_name()+                               "'s attack with his left claw !\n");
	    return;
	}
	else if (random(100) < 18) {
	    tell_room(environment(),"Baal-Rog buffets "+this_player()->query_name()+                               "'s attack with its wings !\n");
	    return;
	}
	return ::hit_player(dam);
    }
