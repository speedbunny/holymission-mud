id(str) { return str == "hole"; }

short() {
    return "A hole";
}

long() {
    write("It's a nice round hole, made with an axe.\n");
}

init() {
    add_action("enter", "enter");
}

enter (str) {
    if (!id(str))
        return 0;
    write("The water is too cold to swim in. You'd die immediately!\n");
    return 1;
}

