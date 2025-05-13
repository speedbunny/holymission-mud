inherit "/std/obj/book";

void reset(int iArg){
    ::reset(iArg);
    if(!iArg) {
        set_name("Bound in red leather, a book entitled 'The Force'");
        set_alias("force");
        set_short("The Force\n");
        set_long("This is a book about the Force \
If you 'open force', you will probably be able to read it.\n");
        set_weight(1000);
        set_pages(5);
        set_book("/players/mangla/guild/book1/page");
    }
}
