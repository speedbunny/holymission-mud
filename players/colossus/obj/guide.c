inherit "/obj/treasure";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_short=("A newbie guide.\n");
    set_long(
      cat("/players/colossus/obj/dispguide");
    );
    set_weight(1);
    set_value(0);
}
