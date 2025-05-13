inherit "obj/monster";

#include "/players/mangla/defs.h"

#define tr(str)\
  tell_room(environment(this_object()),"Contract Broker says: " + str + "\n")

string  hunter, hunted, asker;
int     money_needed;

int add_money(int m) {

    if(this_player()->query_immortal()) {
        tr("I do not accept wizards' money!\n");
        return 1;
    }
    money_needed-=m;
    if(money_needed>0)
        tr("I still need paid " +
               money_needed + " coins.\n");
    else {
        tr("The contract can now be fulfilled.\n");
    }        
}

int _contract(string str) {

    object hunter_ob, hunted_ob;

    if(!str) {
        write("Proper usage: contract who to kill who\n");
        return 1;
    }
    if(sscanf(str,"%s to kill %s",hunter,hunted) != 2) {
        write("Proper usage: contract who to kill who\n");
        return 1;
    }
    if(money_needed < 1) {
        asker = TP->RNAME;
        hunter_ob = find_player(hunter);
        hunted_ob = find_player(hunted);
        if(!objectp(hunter_ob) || !objectp(hunted_ob)) {
            tr("One of the parties is not to be found. All parties must\n" +
               "be found before a contract can be made.\n");
            return 1;
        }
        log_file("CONTRACTS","On " + ctime(time()) + " " + asker +
                             " contracted " +
                             hunter + " to kill " + hunted + ".\n");
        tr(CAP(hunter) + " may now seek out " + CAP(hunted) + ".\n" +
           "You have 48 hours from " + ctime(time()) +
           " to fulfill the contract.\n" +
           "Otherwise it will have to be renewed.\n" +
           "Any other payments to " + CAP(hunter) +
           " are your own business.\n");
        shout("Contract Broker shouts: A contract has been signed!\n");
        return 1;
    }
    else {
        tr("You must pay me " + money_needed + " first.\n");
        return 1;
    }
    return 0;
}

int _list_them() {

    tell_object(TP,"Most recent contracts.\n");
    tail("/log/CONTRACTS");
    return 1;
}

void reset(int arg) {

    ::reset(arg);

    if(arg) return;

    set_name("contract broker");
    set_alias("broken");
    set_alt_name("contract");
    set_hp(10000000);
    set_race("man");
    set_short("Contract Broker");
    set_long("A dark man who has a look of power about him.\n" +
             "He certifies contracts on players lifes. If you want to\n" +
             "have someone killed, you can come to him and he will\n" +
             "verify and log the contract. Any unauthorized contracts\n" +
             "impinge on his business and will be solved with extreme\n" +
             "prejudice in an expediant manner.\n");
    set_level(100);
    set_wc(90);
    set_whimpy(-1);
    set_ep(1);
    set_trapped(1);
    money_needed = 100000;
}

init() {
    ::init();
    add_action("_contract", "contract");
    add_action("_list_them", "list");
}

