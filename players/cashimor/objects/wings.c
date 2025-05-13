short() {
    return "Fairy wings";
}

long() {
   write("They look very fragile, but seem to be capable of lifting great weights.\n");
}

init() {
     add_action("dust","dust");
}

id(str) {
    return str == "wings";
}

object dust;

dust(str) {
     object who;
     if (!str) return 0;
     who = present(lower_case(str), environment(this_player()));
     if (!who || !living(who))
        return 0;
     dust = clone_object("/players/cashimor/objects/powder");
     move_object(dust,who);
     write("You spray dust all over "+call_other(who,"query_name")+".\n");
     say(call_other(who,"query_name")+" is sprayed with fairy dust!\n");
     return 1;
}

query_weight() { return 1; }
get() {
    return 1;
}
