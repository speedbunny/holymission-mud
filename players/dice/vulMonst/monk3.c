inherit "obj/monster";

int count;
query_property(str) { return str=="no_clean_up"; }

reset(arg) {
    ::reset(arg);
    if(arg) return;
    count=0;
    set_name("old monk");
    set_alt_name("monk");
    set_race("human");
    set_gender(1);
    set_short("An old monk");
    set_long("This is an old and wandering monk\n"+
      "It seems like the has traveled a long way\n"+
      "His monk robe is totally worn out, and his sandals are in bad condition.\n");
    set_level(16);
    set_wc(32);
    set_al(-125);
    set_whimpy(50);
    transfer(clone_object("/players/dice/vulObj/mrobe"),this_object());
    transfer(clone_object("/players/dice/vulObj/sandals"),this_object());
    command("wear robe");
    command("wear sandals");
    add_money(100+random(401));
    set_dead_ob(this_object());
}

heart_beat() {
    if(++count>4) {
	random_move();
	count=0;
    }
    ::heart_beat();
}

monster_died() {
    /*
	    "players/moonchild/goblins/disp"->more();
    */
    return;
}
