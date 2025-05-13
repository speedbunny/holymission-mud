inherit "obj/monster";

object obj;

int attack() {

    if(!attacker_ob) return 0;

    printf("The brownie frowns and says: Why do attack me?\n");
    say("The brownie frowns and says: Why do attack me?\n");
    printf("He makes a magical gesture and vanishes!\n");
    say("He makes a magical gesture and vanishes!\n");
    move_object(this_object(),"players/kelly/store");
    return 1;
}

int comfort(string str) {

    if(!id(str)) return 0;
    cat("/players/kelly/obj/brownie_story.txt");
    return 1;
}

int catch_tell(string str) {

    string  who,what,towhom;

    if(sscanf(str,"%s gives %s to %s.",who,what,towhom)!=3) return 0;
    if(what=="hat" && towhom=="Brownie" && present("browniehat")) {
        write("The brownie thanks you wholeheartedly and disapears.\n");
        write("You see that he has left something behind!\n");
        obj=clone_object("/players/kelly/obj/part1");
        move_object(obj,environment());
        move_object(this_object(),"players/kelly/store");
    }
    return 1;
}


reset(arg) {

    ::reset(arg);
    if (arg) return;

    set_name("brownie");
    set_short("A brownie");
    set_long("A little brownie, just sitting here and crying bitterly.\n");
    set_ac(1);
    set_male();
    set_race("gnome");
    set_size(2);
    set_level(19);
    set_al(1000);
    set_wc(1);
    set_aggressive(0);
}

init() {

    ::init();
    add_action("comfort","comfort");
}

