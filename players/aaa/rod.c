
/* Idea from /room/south/sshore24.c */
/* Completed 27.01.1995 */

inherit "/obj/treasure";
int usage;

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    usage=0;
    set_name("fishing rod");
    set_alt_name("aaa-special-fishingrod");
    set_short("a fishing rod");
    set_alias("rod");
    set_value(80);
    set_weight(1);
    set_long("A long brown bambus stick with a long cord fixed to it. "+
             "On the end of the cord is an imagination of a worm and a "+
             "hook. It looks like this stick can help you to catch "+
             "fishes!\n");
}

void set_in_use(int arg) {
    usage=arg;
}

int query_in_use() {
    return usage;
}
