#include "/players/sargon/define.h"

#define GM 	"/guild/master"
#define GUILD	"fighter"
#define BIN	"/players/sargon/guild/skills/"

int is_berzerk, gd, bash, butt;
object berz_where, env;

//--- Butt functions ---

void reset_butt() {
    butt = 0;
}

void set_butting() {
    butt = 1;
    call_out("reset_butt", 0, 1);
    return;
}

int query_butting() {
    return butt;
}

//--- Bash functions ---

void reset_bash() {
    bash = 0;
}

void set_bash() {
    bash = 1;
    call_out("reset_bash", 0, 1);
    return;
}

int query_bash() {
    return bash;
}

//--- Berzerk functions ---

void anti_berz() {
    if(env)
        tell_object(env, "You get tired, and turn back normal.\n");
    is_berzerk = 0;
    return;
}

void calm_stop() {
    if(is_berzerk) {
        remove_call_out("anti_berz");
        is_berzerk = 0;
        tell_object(env, "You feel that your are completely calm once"
                        +" again.\n");
    }
    return;
}

//--- NB. The arg is used for the call_out time ---
void set_berzerk(int arg) {
    if(arg) {
        is_berzerk = 1;
        berz_where = E(env);
        call_out("anti_berz", arg);
    }
    else
        call_out("calm_stop", 6);
    return;
}

int query_berzerk() {
    return is_berzerk;
}

//--- General filter function to handle guild commands ---

int guild_command(string str) {
    string verb;

    verb = query_verb();

    if(verb == "quit" || verb[0..0] == "'" || member(verb, '.') != -1)
        return 0;

    else if(verb == "fighter/" || verb == "fighter:")
        return (BIN+"fighter")->fighter(str);

    else if(file_size(BIN+verb+".c") < 1) {
        return 0;
    }

    else
        return call_other(BIN+verb, verb, str);
} 

//--- Used to hit the monster twice ---

void recognize_fight() {
    object enmy;

    if(!previous_object() || !(E(previous_object()))) {
        destruct(this_object()); // Herp: probably in case of linkdeath
        return;
    }

    enmy = env->query_attack();
#if 0
    if(!enmy) return; // Sauron: Just making sure.
#endif

    env->attack();
    env->attack();

    if(is_berzerk && enmy) {
        if(E(env) == E(enmy)) {
            tell_object(env, "++++ ");
            env->attack();
            if(env->query_level() > 23) {
                tell_object(env, "#### ");
                env->attack();
                env->attack();
            }
            return;
        }
        else {
            if(E(env) != berz_where)
                tell_object(env, "You cowardly run away from battle!"
                                +" You're NO longer berzerk.\n");
            else
                tell_object(env, "You calm down as your enemy flees.\n");
            remove_call_out("anti_berz");
            is_berzerk = 0;
            return;
        }
    }
}

//--- General object functions ---

int id(string str) {
    return str == "fighter_soul" || str == "fightersoul";
}

int get()  {
    return 1;
}

int drop() {
    return 1;
}

void reset(int arg) {
    if(arg) return;
    gd = GM->query_number(GUILD);
}

void init() { 
    object shadow;

    "/sys/chatd"->do_chat(gd, "You suddenly feel the blood rushing"
                             +" strongly through your veins.\n");

    add_action("guild_command",	"", 1);
    env = E();

    if(!env->parry_shad())  {
        shadow = CO("/players/sargon/guild/skills/parry_shad");
        shadow->start_shadow(env, 0, "parry_shad");
    }
}
