inherit "obj/weapon";
void reset(int arg) {
    ::reset();
    set_name("lizard sword");
    set_short("Lizard sword");
    set_alias("sword");
    set_class(13);
    set_type("sword");
    set_weight(2);
    set_value(3000);
    set_long("This sword once belonged to a lizard.\n");
}
