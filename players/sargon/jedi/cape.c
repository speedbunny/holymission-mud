inherit "obj/armour";

#include "/players/mangla/defs.h"

#define guild "guild/master"->query_number("jedi")

reset(arg) {
    ::reset(arg);
    if (!arg) {
        set_name("jedicloak");
        set_alias("cloak");
        set_short("A midnight blue Jedi-cloak");
        set_long("This is you Jedi-Cloak.\n" +
                 "You should wear it with pride.\n" +
         "For more help on features this cloak might possess\n" +
         "just type 'help cloak'\n");
        set_ac(1);
        set_value(0);
        set_weight(1);
        set_type("cloak");
    }
}

get() {
    remove_call_out("fade_away");
    return 1;
}

drop() {
    ::drop();
    call_out("fade_away",30);
    return 0;
}

wear(str) {
    if(!id(str)) return;
    if(TP->query_guild()!=guild) {
        write("A strong Force keeps you from wearing this cloak.\n");
        return 1;
    }
    ::wear(str);
    if(!worn) return;
    TP->set_ac((TP->DEX/26)+1);
    write("You feel the Force take control of your mind and body.\n");
    say(TP->NAME+" somehow looks more powerful.\n");
    return 1;
}

fade_away() {
  if(!living(environment(this_object())) &&
                environment(this_object())->guery_guild() != 4) {
    tell_room(ENV(TO),"The cloak gets indistinct and fades away.\n");
    destruct(TO);
  }
  return 1;
}

_set_color(arg) {

    switch(arg) {
        case "1": set_short("A blue Jedi-cloak");
                    write("Set to blue.\n");
                    return 1; break;
        case "2": set_short("A red Jedi-cloak");
                    write("Set to red.\n");
                    return 1; break;
        case "3": set_short("A black Jedi-cloak");
                    write("Set to black.\n");
                    return 1; break;
        case "4": set_short("A forest green Jedi-cloak");
                    write("Set to forest green.\n");
                    return 1; break;
        case "5": set_short("A orange Jedi-cloak");
                    write("Set to orange.\n");
                    return 1; break;
        case "6": set_short("A brown Jedi-cloak");
                    write("Set to brown.\n");
                    return 1; break;
        case "7": set_short("A grey Jedi-cloak");
                    write("Set to grey.\n");
                    return 1; break;
        case "8": set_short("A white Jedi-cloak");
                    write("Set to white.\n");
                    return 1; break;
        return 0;
    }
}

_help(str) {

    if(str == "cloak") {
        write("You cloak has 8 colors it can impersonate.\n" +
              "Choose a color 1-8 with:\n" +
              "    cloak_color #\n");
        return 1;
    }
    return 0;
}

init() {
    ::init();
    add_action("_set_color","cloak_color");
    add_action("_help","help");
}

