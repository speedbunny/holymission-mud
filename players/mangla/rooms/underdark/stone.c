inherit "obj/treasure";

void reset(int arg) {

    ::reset(arg);
    if(arg) return;
    set_name("Yellow Stone");
    set_alias("stone");
    set_short("A small stone");
    set_long("A small stone that seems to glow with its own light.\n" +
             "This yellow stone appears to be of some value.\n");
    set_weight(3);
    set_light(1);
    set_value(300);
    set_id("ystone");
}

