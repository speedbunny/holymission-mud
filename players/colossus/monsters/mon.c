inherit "/obj/monster";
string name;
object mon,corpse;
reset(arg) {
    ::reset(arg);
    if (!arg) {
        set_name("general");
        set_level(15);
        name = "General LaMarque";
        set_heart_beat(1);
    }
}
id(str) { return str == "general"; }
short() { return name; }
change() {
    string name,aob,maob;
    aob = attacker_ob;
    maob = attacker_ob;
    if (random(2)+1 == 1) {
        mon = clone_object("/players/rhonin/monsters/mon1");
        /* Do a set_ep() here so that the player will get the right */
        /* amount of xp for the monster ( mon->set_ep(int ep); =) */
        move_object(mon,environment(this_player()));
    }
    else {
        mon = clone_object("/players/rhonin/monsters/mon2");
        /* Do a set_ep() here so that the player will get the right */
        /* amount of xp for the monster ( mon->set_ep(int ep); =) */
        move_object(mon,environment(this_player()));
    }
    if (attacker_ob) {
        attacker_ob->stop_fight();
        stop_fight();
        attacker_ob = 0;
        set_heart_beat(1);
    }
    name = mon->query_name();
    command("kill "+name,aob);
    mon->attack_object(maob);
    return 1;
}
heart_beat() {
    ::heart_beat();
    if (attacker_ob) {
        name = 0;
        tell_room(environment(this_object()),"The general changes "+
        "shape into a monster.\n");
        change();
    }
    if (!mon && !name) {
        tell_room(environment(this_object()),
            "The monster died a horrible death, and before your "+
            "eyes, the dead monster turns back into the shape of "+
            "the corpse of general LaManque.\n");
        destruct(present("corpse",environment(this_object())));
        corpse = clone_object("/obj/corpse");
        corpse->set_name("general LaMarque");
        transfer_all_to(corpse);
        move_object(corpse,environment(this_object()));
        destruct(this_object());
    }
}
