#pragma strict_types;

inherit "/obj/treasure";

string let,which,what,name;
int amm,invis;

#define TP this_player()
#define TPRN this_player()->query_real_name()
#define QN query_name()
#define CP capitalize
#define WR write
#define TO this_object
#define AA add_action
#define PATH "/tools/"

int done();
int done2();
int done3();
void reset(int arg) {

    if(arg) return;
    name=TPRN;
    set_id("wizards rock");
    set_alias("rock");
    set_long("This very sturdy looking rock was probably coded by Arthur.\nIt has many neat funtions built into it. To learn more about the set function\nType 'help set', and to learn more about the add function type 'help add'.\n");
    set_value(0);
    set_weight(0);
}

string short() {
    if(invis) return "";
    else return environment(TO())->query_real_name()+"'s wiz rock";
}

void init() {
    AA("_add","add");
    AA("_set","set");
    AA("_help","help");
    AA("_move","rockto");
    ::init();
}

int _help(string str) {

    if(str == "set") {

        WR("The current functions of Arthurs wiz rock are:\n\n"+
          "set <argument> <number or string>\n"+
          "\nThis is the list of current <argument>'s for the set function.\n"+
          "str <number> - sets the strength to between 1 and 40\n"+
          "wis <number> - sets the wisdom to between 1 and 40\n"+
          "int <number> - sets the intellegence to between 1 and 40\n"+
          "dex <number> - sets the dexterity to between 1 and 40\n"+
          "chr <number> - sets the chrisma to between 1 and 40\n"+
          "con <number> - sets the constitution to between 1 and 40\n"+
          "al <number> - sets your alignment\n"+
          "n_ac <number> - sets your natural armour class\n"+
          "n_wc <number> - sets your natural weapon class\n"+
          "religion <string> - sets your religion to <string>\n"+
          "race <string> - sets your race to <string>\n"+
          "smell <string> - sets your smell to <string>\n"+
          "rock <str> - <str> can be invisible or visible\n");
        return 1;
    }
    if(str =="add") {
        WR("The current add functions for Arthur's Wiz rock are:\n\n"+
          "This is the list of current <argument>'s for the add function.\n\n"+
          "hp <num> - adds <num> ammount of hit-points to you\n"+
          "xp <num> - adds <num> ammount of experience to you\n");
        return 1;
    }
    if(str == "rock") {
        WR("The wiz rock says: I have two functions. Set and add. You can\n\
get help on either of them. Use 'rockto <appr>' to send rock\n\
to an appr wiz.\n");
        return 1;
    }
    else
        return 0;
}

int _add(string str) {

    if(!str) return 0;
    if(sscanf(str,"%s",which) == 1)
        amm = 0;
    sscanf(str,"%s %d",which,amm);

    switch(which) {
    case "xp": 
        if(!amm) {
            WR("To add xp type 'add xp <number>'.\n");
            return 1;
        }
        // Mangla: limit placed in here to stop ridiculous XP             
        if((int)TP->query_exp() > 10000000) break;
        TP->add_experience(amm);
        done2();
        return 1;  
        break;
    case "hp":
        if(!amm) {
            WR("To add hp it would be 'add hp <number>'.\n");
            return 1;
        }
        if(TP->query_hp() >= TP->query_max_hp()) break;
        if( (TP->query_max_hp()) - (TP->query_hp()) < amm) break;
        TP->reduce_hit_point(-amm);
        done2();
        return 1;
        break;
    default:
        return 0;
    } 
}

int _set(string str) {

    if(!str) {
        WR("what do you want to set, and to what?\n");
        return 1;
    }
    if(sscanf(str, "%s", which) == 1)
        what = 0;
    sscanf(str,"%s %s",which,what);
    switch(which) {
    case "rock":
        if(!what) {
            WR("To set the rock invisible type 'set rock invisible', for it to be visible\ntype 'set rock visible'.\n");
            return 1;
        }
        if(what =="invisible") invis = 1;
        else invis = 0;
        write("Your rock is now visible.\n");
        return 1;
        break;
    case "race":
        if(!what) {
            WR("To set your race type 'set race <string>'.\n");
            return 1;
        }
        TP->set_race(what);
        done3();
        return 1;
        break;
    case "religion":
        if(!what) {
            WR("To set your religion type 'set religion <string>'.\n");
            return 1;
        }
        TP->set_religion(what);
        done3();
        return 1;
        break;
    case "smell":
        if(!what) {
            WR("To set your smell type 'set smell' <string>'.\n");
            return 1;
        }
        TP->set_smell(what);
        done3();
        return 1;
        break;
    default:
        which = 0;
    }


    if(sscanf(str, "%s", which) == 1)
        amm=0;
    sscanf(str,"%s %d",which,amm);
    switch(which) {
    case "dex": 
        if(!amm) {
            WR("To set your dex type 'set dex <number>'.\n");
            return 1;
        }
        if(amm < 500)
            TP->set_dex(amm);
        done();
        return 1;
        break;
    case "con":
        if(!amm) {
            WR("To set your con type 'set con <number>'.\n");
            return 1;
        }
        if(amm < 500)
            TP->set_con(amm);
        done();
        return 1;
        break;
    case "str":
        if(!amm) {
            WR("To set your str type 'set str <number>'.\n");
            return 1;
        }
        if(amm < 500)
            TP->set_str(amm);
        done();
        return 1;
        break;
    case "wis":
        if(!amm) {
WR("To set your wis type 'set wis <number>'.\n");
            return 1;
        }
        if(amm < 500)
            TP->set_wis(amm);
        done();
        return 1;
        break;
    case "chr": 
        if(!amm) {
            WR("To set your chr type 'set chr <number>'.\n");
            return 1;
        }
        if(amm < 500)
            TP->set_chr(amm);
        done();
        return 1;
    WR("I set your "+which+" to: "+amm+".\n");
    return 1;
}

int done2() {
    WR("I added "+amm+" to your "+which+".\n");
    return 1;
}

int done3() {
    WR("I Changed "+which+" to: "+what+".\n");
    return 1;
}


#if 0
init_arg(int arg) {
}
#endif

