inherit "/players/mangla/objects/book";

reset(int arg) {

    ::reset(arg);
    set_book("/players/kryll/fighters/page");
    set_pages(6);
    set_name("Help book");
    set_long("Instruction manual to Lenfor.\n");
}

init() {
    ::init();
}
