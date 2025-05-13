inherit "obj/monster";
object cap,jacket;

#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("ranma");
    set_alias("Ranma");
    set_short("Ranma Saotome");
    set_long("Cursed by the waters of the Sacred Cursed Springs, Ranma will\n" +
    "change to a female if wet by cold water. He is a great material artist\n" +
    "trained to prefection with his father, Genma Saotome. You will\n" +
    "recognize him by his trademark black pigtail and chinese clothings.\n");
	set_level(150);
    set_gender(1);
  set_hp(1);
    set_race("anime");
	add_money(100000000);
    set_wc(20);
    set_ac(12);
	set_number_of_arms(0);
    cap=clone_object("/players/tinman/armors/ranma_cap");
    move_object(cap,this_object());
    jacket=clone_object("/players/tinman/armors/ranma_jac");
    move_object(jacket,this_object());
	set_dead_ob(this_object());
	experience=999999;
}
heart_beat(){
    ::heart_beat();
    if(AO && present(AO, environment()) ) {
	if(!random(5)) {
            tell_object(AO, "Ranma shouts Hiryu-do-ken-ha and blasts you toward the sky!!\n");
            say("Ranma shouts Hiryu-do-ken-ha and blasts "+AO->query_name()+" toward the sky!!\n",AO);
            AO->hit_player(40);
	}
	else if (!random(6)) {
            tell_object(AO, "Ranma shouts Ana-doi-ken and shoots a FireBall at you!!!\n");
            say("Ranma shouts Ana-doi-ken and shoots a FireBall at "+AO->query_name()+"!\n",AO);
            AO->hit_player(30);
	}
    }
}

