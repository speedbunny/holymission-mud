inherit "obj/monster";

int ask(string str) {

    if(str!="druid") return 0;
    write("The druid says: Sorry, but currently nothing else is available!\n");
    return 1;
}

int attack() {

    if(!attacker_ob) return 0;
    tell_object(attacker_ob,"The druid makes a magical gesture.\n"+
                "You don't feel good.\n" +
                "You begin to panic.\n" +
                "You don't know what to do.\n");
     attacker_ob->run_away();
     ::attack();
     return 1;
}

walk_around() {

    init_command("e");
    call_out("walk_around2",3600);
    return;
}

walk_around2() {

    init_command("w");
    call_out("walk_around",3600);
    return;
}

reset(int arg) {

    ::reset(arg);
    if (arg) return;

    set_name("druid");
    set_short("The Faun-druid");
    set_long("The druid of this Faun village, he looks very old and expierenced.\n" +
             "He certainly possesses magical powers.\n");
    set_level(11);
    set_race("faun");
    set_male();
    set_size(3);
    set_al(500);
    set_aggressive(0);
    call_out("walk_around",3600);
}

init() {

    ::init();
    add_action("ask","ask");
}


