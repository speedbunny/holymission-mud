inherit "/obj/weapon";

int charges;

void reset(int flag){

    if (flag) return;

    charges =(5 + random(15));
    set_name("Sword of Fireballs");
    set_alias("sword");
    set_type(1);
    set_class(20);
    set_short("The Sword of Fireballs");
    set_long("This is Nyphur's sword of fireballs.  With this weapon he was able to summon \n"+ 
             "magic fireballs upon his enemies.  With the magic command 'fireball <monster>' \n"+ 
             "you too can cast this spell.  However, the magic contained in this weapon is \n"+
             "limited, so be careful how you use it.\n");
    set_value(4000);
    set_weight(4);
    
}

int init() {
    add_action("do_use", "fireball");
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


    write("You summon a magic fireball against "+player->query_name()+"!\n");
    say(this_player()->query_name()+" summons a magic fireball against "+ 
        player->query_name()+"!\n",this_player(), player);
    tell_object(player, this_player()->query_name()+" summons a magic fireball against you!\n"); 
    charges--;

    write(player->query_name()+" gets burned!\n");
    say(player->query_name()+" gets burned!\n", player);
    tell_object(player,"You get burned!\n");
    player->attack_object(this_player());
    player->hit_player( 50 + random(50),5);
    return 1;                             
}
