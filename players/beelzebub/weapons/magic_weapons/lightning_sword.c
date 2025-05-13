inherit "/obj/weapon";

int charges;

void reset(int flag){

    if (flag) return;

    charges =(5 + random(15));
    set_name("Lightning Sword");
    set_alias("sword");
    set_type(1);
    set_class(20);
    set_short("Lightning Sword");
    set_long("This is Jark's lightning sword.  With this weapon he was able to summon \n"+ 
             "lightning bolts upon his enemies.  With the magic command 'lightning <monster>'\n"+ 
             "you too can cast this spell.  However, the magic contained in this weapon is \n"+
             "limited, so be careful how you use it.\n");
    set_value(7000);
    set_weight(4);
    
}

int init() {
    add_action("do_use", "lightning");
    ::init();
}


int do_use(string str) {

    string target;
    object player, room;

    if (!str || (sscanf(str, "%s",target) != 1))
        return 0;
    if (!query_wielded()) {
        notify_fail("You have to wield the sword before you can use it.\n");
        return 0;
    }
    if (!charges) {
        notify_fail("Your sword has been drained of its magic power.\n");
        return 0;
    }

    player = present(target, environment(this_player()));
    room = environment(this_player());

    if (!player || (environment(player) != room)) {
        notify_fail("Nothing by that name here.\n");
        return 0;
    }


    write("You summon a lightning bolt against "+player->query_name()+"!\n");
    say(this_player()->query_name()+" summons a lightning bolt against "+ 
        player->query_name()+"!\n",this_player(), player);
    tell_object(player, this_player()->query_name()+" summons a lightning bolt against you!\n"); 
    charges--;
                                    
    write(player->query_name()+" gets electrocuted!\n");
    say(player->query_name()+" gets electrocuted!\n", player);
    tell_object(player,"You get electrocuted!\n");
    player->attack_object(this_player());
    player->hit_player( 60 + random(60),5);
    return 1;                             
}
