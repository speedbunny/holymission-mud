inherit "obj/monster";

string func,match,type;

int handle_give(string str) {

    string who;
    int money;

    if(sscanf(str,"%s gives you %d gold coins.",who,money)!=2) {
        say("The drunkard looks puzzled.\n");
        return 1;
    }
    if(query_money()>=200) {
        init_command("buy brew");
        say("The drunkard says: Thanx , Shtranger, you've shafed life.\n");
        return 1;
    }
    if(query_money()>=5) {
        init_command("buy cervisia");
        say("The drunard says: Yeah, well , better than nothing. Hick.\n");
        return 1;
    }
}

int handle_leave(string str) {

    string who,dir;
    object leaver;

    if(sscanf(str,"%s leaves %s.",who,dir)!=2) {
        say("The drunkard looks puzzled.\n");
        return 1;
    }
    if(leaver=find_player(who))
        tell_object(leaver,"The drunkard shouts after you: Hey, why d'ya leave, haeh?\n");
    return 1;
}

set_array() {

    func= allocate(2);
    match= allocate(2);
    type= allocate(2);

    func[0] = "handle_give";
    match[0] = "";
    type[0] = "gives";
    func[1] = "handle_leave";
    match[1] = "";
    type[1] = "leaves";
}

reset(arg) {

    ::reset(arg);
    if (arg) return;

    set_name("drunkard");
    set_race("faun");
    set_size(3);
    set_male();
    set_level(5);
    set_al(50);
    set_short("A drunkard");
    set_long("A really drunk Faun. Never seen this before.\n");
    set_aggressive(0);
    set_array();
    set_match(this_object(),func,type,match);
    load_chat(5,({"The drunkard says: I need a drink.\n",
                  "The drunkard doubles over and pukes on his shoes.\n",
                  "The drunkard says: Can you spare me some coins for a drink?\n",
                  "The drunkard murmurs something about Middleearth.\n",
                  "The drunkard says: I know many talesh of the old timesh.\n"
                }));
    load_a_chat(3,({"The drunkard pukes on you.\n",
                    "The drunkard says: Why do you do thish to me, hick.\n",
                    "The drunkard shouts: Shit.\n",
                  }));

}

