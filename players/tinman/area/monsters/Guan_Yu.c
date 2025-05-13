inherit "obj/monster";
object dragon,jplate,ghelmet,gauntlet,pant,boot;

#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Guan Yu");
    set_alias("guan");
    set_short("Wargod Guan Yu");
    set_long("A huge middle age man with long black beard. He looks as if he"+
      " can break you in half. He's the blood brother of Liu Bei and Zhang Fei. "+
      "He is also the chinese war god so becareful you don't attack him.\n");
    set_level(125);
    set_gender(1);
    set_race("war god");
    add_money(10000+random(20000));
    set_n_wc(35);
    set_dead_ob(this_object());
    set_n_ac(45);
    set_number_of_arms(2);
    dragon=clone_object("/players/tinman/area/weapons/dragon");
    move_object(dragon,this_object());
    jplate=clone_object("/players/tinman/area/armors/jplate");
    move_object(jplate,this_object());
    ghelmet=clone_object("/players/tinman/area/armors/ghelmet");
    move_object(ghelmet,this_object());
    gauntlet=clone_object("/players/tinman/area/armors/gauntlet");
    move_object(gauntlet,this_object());
    pant=clone_object("/players/tinman/area/armors/pant");
    move_object(pant,this_object());
    boot=clone_object("/players/tinman/area/armors/boot");
    move_object(boot,this_object());
    command("powerup");
}
heart_beat(){
    ::heart_beat();
    if(AO && present(AO, environment()) ) {
	if(!random(5)) {
	    tell_object(AO, "The war god brings down his black dragon and rip"+
	      " your arm off from it's socket!!!!!\n");
	    say("The war god brings down his black dragon and rip "+AO->query_name()+"'s arm off from it's socket!!!!!\n",AO);
	    AO->hit_player(80);
	}
	else if (!random(6)) {
	    tell_object(AO, "Guan Yu brings down his black dragon and barely misses you!\n");
	    say("Guan Yu brings down his black dragon and barely misses "+AO->query_name()+"!\n",AO);
	    AO->hit_player(20);
	}
    }
}

monster_died(ob){
    write("You have defeated the War God Guan Yu in combat!\n");
    shout(this_player()->query_name()+
      " has defeated the War God Guan Yu in combat!\n");
    return 0;
}
