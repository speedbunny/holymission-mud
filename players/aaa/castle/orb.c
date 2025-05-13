
/* Completed 07.02.1995 */

inherit "/obj/treasure";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_alias("anti-field emitter");
    set_name("orb");
    set_short("a glowing orb");
    set_value(2000);
    set_weight(0);
    set_long("This orb is made of a glancing metal. You can recognize the "+
             "rune of penetration engraved in it.\n");
}

drop() {
    write("As the orb leaves your hands, it disintegrates.\n");
    destruct(this_object());
    return 1;
}

put() {
    write("As the orb leaves your hands, it disintegrates.\n");
    destruct(this_object());
    return 1;
}

give() {
    write("As the orb leaves your hands, it disintegrates.\n");
    destruct(this_object());
    return 1;
}   

int query_no_store() {return 1;}
