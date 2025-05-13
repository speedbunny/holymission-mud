inherit "obj/thing";

#include "/players/mangla/defs.h"

int     open;
string  *items;
int     amount,all_money;


id(str) {

    return (str=="dispenser"
         || str=="slot"
         || str=="mcd"
         || str=="manual"
         || str=="buttons"
         || str=="drawer");
}

long(str) {

   if(str=="dispenser") {
       write("This is a goodie dispenser.\n" +
             "You can see a manual attached to its side, several buttons,\n" +
             "and a slot to insert coins. At the bottom-right you see graffiti\n" +
             "saying 'Nokey is a Geek'\n");
       return 1;
    }
    if(str=="manual") write("You can read it.\n");
    if(str=="slot") write("A slot to insert gold coins.\n");
    if(str=="buttons") write("You can read what they say.\n");
    return 1;
}

_kick(str) {

    if(str == "dispenser") {
        TELLR(ENV(TO),TP->NAME + " tries to kick the dispenser, misses\n" +
                      "and gets kicked by the dispenser for their mischief.\n");
        return 1;
    }
    return 0;
}

_read(str) {

    int nr,i;

    if(str=="manual") {
        cat("/players/mangla/guild/dman");
        return 1;
    }
    if(str == "buttons" || str == "button") {
        nr=sizeof(items);
        write("The "+(nr+1)+" buttons are labeled.\n");
        printf("Button %-4d %-30s\n",1,"Cancel-Button");
        for(i=0;i<nr;i++)
            printf("Button %-4d %-30s %-4d\n",i+2,
                   items[i]->short(),
                   items[i]->query_value()*2);
        return 1;
    }
    return 0;
}

_insert(str) {

    int how_many;

    if(!str) return 0;

    if(sscanf(str,"%d coins",how_many)!=1) {
        write("Use the syntax 'insert ## coins'\n");
        return 1;
    }

    if (TP->query_money() < how_many) {
        write("You do not have that many coins!\n");
        return 1;
    }
    TP->add_money(-how_many);
    all_money += how_many;
    write("You insert " + how_many + " coins into the slot.\n");
    return 1;
}

_buy_item(nr) {

    if(!nr) {
        write("You've pressed the CANCEL-button.\n");
        write("You lose all your money!\n");
        all_money = 0;
        return 1;
    }

    if(items[nr-1]->query_value()*2 > all_money) {
        write("Nothing happens.\n");
        return 1;
    }
    all_money -= items[nr-1]->query_value()*2;
    write("You press the button and feel a tingling on your body.\n");
    say(TP->NAME + " presses a button.\n");
    if(transfer(clone_object(items[nr-1]),TP)) {
        printf("You cannot carry that, the dispenser notices, and just takes your money instead!\n");
    }
    return 1;
}

_press(str) {

    int nr;

    if(sscanf(str,"button %d",nr)!=1) return 0;

    if((nr < 1) || (nr >= sizeof(items)+2)) {
        write("There is no button " + nr + ".\n");
        return 1;
    }
    _buy_item(nr-1);
    return 1;
}



reset(arg) {

    ::reset(arg);
    if(arg) return;

    set_name("Dispenser");
    set_alias("dispenser");
    set_short("Item Dispenser");
    set_long("This is a goodie dispenser.\n" +
             "You can see a manual attached to its side, several buttons,\n" +
             "and a slot to insert coins. At the bottom-right you see graffiti\n" +
             "saying 'Nokey is a Geek'\n");
    set_weight(100);

    open=0;
    amount=0;
    all_money=0;
    items=({"players/kelly/obj/knife",
            "players/kelly/obj/glowworm",
            "players/kelly/obj/watch",
            "players/mangla/guild/lightsaber",
            "players/mangla/guild/cloak",
            "players/kelly/obj/salve",
    });
}


init() {
    ::init();
    add_action("_insert","insert");
    add_action("_kick","kick");
    add_action("_read","read");
    add_action("_press","press");
    add_action("_press","push");
}
