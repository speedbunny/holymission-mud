inherit "obj/monster";
object cap,jacket;

#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("ranma-chan");
    set_alias("Ranma-chan");
    set_short("Ranma Saotome");
    set_long("She looks smaller in size and is now all wet. You notice that her chest size\n" +
    "increased as so her temper. Her hair is red but you recognize her pigtail.\n" +
    "Hmmm...she's kinda cute.....*smile*\n");
    set_level(45);
    set_hp(7500);
    set_gender(2);
    set_race("anime");
    add_money(1000);
    set_wc(15);
    set_ac(12);
    set_number_of_arms(6);
    cap=clone_object("/players/tinman/armors/ranma_cap");
    move_object(cap,this_object());
    init_command("wear cap");
    jacket=clone_object("/players/tinman/armors/ranma_jac");
    move_object(jacket,this_object());
    command("wear jacket");
}
heart_beat(){
    ::heart_beat();
    if(AO && present(AO, environment()) ) {
	if(!random(5)) {
            tell_object(AO, "Ranma-chan shouts Hiryu-do-ken-ha and blasts you toward the sky!!\n");
            say("Ranma-chan shouts Hiryu-do-ken-ha and blasts "+AO->query_name()+" toward the sky!!\n",AO);
            AO->hit_player(40);
	}
	else if (!random(6)) {
            tell_object(AO, "Ranma-chan shouts Ana-doi-ken and shoots a FireBall at you!!!\n");
            say("Ranma-chan shouts Ana-doi-ken and shoots a FireBall at "+AO->query_name()+"!\n",AO);
            AO->hit_player(30);
	}
    }
}

