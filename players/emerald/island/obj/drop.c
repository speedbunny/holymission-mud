inherit "/obj/treasure";

int drink(string str) {
    if(str == "drop" || str == "oil" || str == "drop of oil") {
        write("A bit oily, but quite tasteful.\n");
        say(this_player()->query_name()+" drinks a drop of oil.\n");
        this_player()->drink_soft(2);
        destruct(this_object());
        return 1;
    }
}

int clean(string str) {
    write("You don't want to make your fingers dirty.\n");
    return 1;
}

int drop() {
    write("How will you drop a drop?\n");
    return 1;
}

void reset(int arg) {
    ::reset(arg);
    if(!arg) {
        set_name("drop");
        set_alias("drop of oil");
        set_short("A drop of oil");
        set_long("A little drop of olive oil.\n");
        set_value(1);
    }
}

void init() {
    ::init();
    add_action("clean", "clean");
    add_action("clean", "polish");
    add_action("drink", "drink");
}
