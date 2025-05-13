inherit "/obj/monster";

void reset(int arg)
 {
 ::reset(arg);
if (arg) return;
set_name("knight Gal Perceval");
set_alias("knight");
set_alt_name("perceval");
set_race("human");
set_gender(1);
set_short("Knight Gal Perceval the member of Round Table");
set_long("Knight Gal Perceval the member of Round Table.\n"+
	 "He is tall, well build.......\n");
set_wc(20);
set_hp(600);
set_ac(1);
set_al(1000);
set_aggressive(0);
set_level(30);
set_size(3);
move_object(clone_object("/players/goldsun/guild/obj/albion"),this_object());
/*
move_object(clone_object("/players/goldsun/guild/obj/iron_shield"),this_object());
move_object(clone_object("/players/goldsun/guild/obj/silver_armour"),this_object());
command("wear armour");
command("wield shield");
*/
command("wield sword");
}

int bar_way_1(object who){
 tell_object(who,"Knight Gal Perceval tells you: You are not allowed to"+
		    "enter this room !\n");
 tell_object(who,"Knight Gal Perceval tells you: DON'T TRY IT AGAIN !!!\n");
 return 1;
}

int bar_way_2(object who){
 tell_object(who,"Knight Gal Perceval tells you: I warned you.\n");
 attack_object(who);
 return 1;
}
 
