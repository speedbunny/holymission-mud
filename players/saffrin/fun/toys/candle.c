inherit "/obj/thing";

reset(arg) {
    ::reset(arg);
    if(arg) return;
set_name("A green candle");
set_alias("candle");
set_short("A green candle");
set_long("A special green candle.\n");
    set_weight(1);
    set_value(10);
}
init() {
    ::init();
}
