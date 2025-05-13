inherit "obj/monster";
object bells,mace;

#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("shampoo");
    set_alias("Shampoo");
    set_short("Shampoo");
    set_long("The Chinese amazon woman who followed Ranma to Japan,\n"+ 
	     "because she was defeated by Ranma-chan and was sworn\n"+
	     "by her martial art to kill her. She then falls in love\n"+
             "with Ranma-kun by the laws of her martial art if a man\n"+
             "should ever defeat her. She has long blue hair with two\n"+
             "buns and bells tied to it.\n");
    set_level(50);
    set_hp(7000);
    set_gender(2);
    set_race("anime");
    set_wc(10);
    set_ac(8);
    set_number_of_arms(5);
    bells=clone_object("/players/tinman/armors/shbell");
    move_object(bells,this_object());
    init_command("wear bells");
    mace=clone_object("/players/tinman/weapons/shmace");
    move_object(mace,this_object());
    command("wield mace");
}
heart_beat(){
    ::heart_beat();
    if(AO && present(AO, environment()) ) {
	if(!random(5)) {
            tell_object(AO, "Shampoo flips and comes down on top of you with\n"+
                       "a swift kick.\n");
            say("Shampoo flips and comes down on top of "+AO->query_name()+"\n" +
               "with a swift kick.\n",AO);
            AO->hit_player(20);
	}
    }
}


