#include "/players/gareth/define.h"
inherit "/obj/monster";
object sword;

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_name("ogre-slug");
	set_short("An ogre-slug");
	set_alias("ogre");
	set_race("slug");
	set_long("This Ogre-Slug has the upper torso, arms, and\n"+
	  "head of an ogre, but the lower body of a large slug.\n" +
	  "It's has a swampy coloring to it; grey-green skin on\n"+ 
	  "the upper body area, fading into a deep blackish green\n"+ 
	  "on th lower half of the body. It looks meaner and uglier\n"+ 
	  "than thier full bodied cousins.\n");
	set_level(65);        
        set_dex(75);
	set_ac(60);
        set_wc(100);
	set_hp(5000);
	set_al(-500);
	set_aggressive(1);
	set_chance(75);
	set_spell_mess1("The ogre-slug smashes his elbow in your face.");
	set_spell_mess2("Ogre-slug whips you with his tail.");
	set_spell_dam(65);
	set_prevent_poison(1);
        add_money(5000);

        sword= TR(CO(ITEM+"scimitar"), TO);
	init_command("wield sword");

    }

}

init(){
    ::init();

    AA("stop_ass", "backstab");	 AA("stop_butt", "headbutt");
    AA("stop_hold", "smash");	 AA("stop_hold", "hold");
    AA("stop_hold", "timehold"); AA("stop_ass", "death");
    AA("stop_that", "bolt");	 AA("stop_that", "lightning");
    // No need for return; here
}

stop_that(who){
    write("Magic is useless against this an orge-slug.\n");
    TP->hit_player(random(35)+55);
    say(TPN+" got blasted by "+QP+" own magic!!\n");
    return 1;
}

stop_ass(who){
    if(id(who)) {
	say(ENV, TPN+" stupidly tried to harm the ogre-slug.\n");
	write("The orge-slug is much to massive for that.\n");
	return 1;
    }
}

stop_hold(who){
    if(id(who)){
	write("The monster resists!\n");
	say("The ogre-slug laughs at"+TPN+".\n");
	return 1;
    }
}

stop_butt(blah){
    if(id(blah)){
	say(ENV, TPN+" tries to bodyblock the creature!\n");
	write("Your body burns as it touches the ogre-slug.\n");
	TP->hit_player(random(50)+30);
	return 1;
    }
}
