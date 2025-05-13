inherit "obj/weapon";
#include "/players/saffrin/defs.h"

reset(arg) {
    if(arg) return;
    set_name(TPQN+"'s Whip");
    set_alias("whip");
    set_weight(4);
    set_class(15);
    set_value(8);
    set_short(TPQN+"'s Whip");
    set_long(
      "This is Saffrin's awesome whip.  This is a special toy\n"+
      "that lets you whip anyone from anywhere!\n"+
      "Use 'whip <name>.\n");
}

init()
{
    ::init();
    AA("whip", "whip");
}

whip(str) {
    object victim;
    victim=find_living(str);
    if(!victim) return write("There is no " + capitalize(str) + " on the game!\n");
    write("You erotically whip "+capitalize(str)+"\n");
    say(CRN+" erotically whips "+capitalize(str)+"\n");
    tell_object(victim,CRN+" erotically whips you.\n");
    if(random(2)) command("moan",victim);
    else command("moan",victim);
    return 1;
}
query_auto_load() {
    return "/players/saffrin/fun/inv/whip:";
}
drop() {
    return 1;
}
