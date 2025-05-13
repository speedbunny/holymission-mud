inherit "/std/obj/book";

void reset(int iArg){
    ::reset(iArg);
    if(!iArg) {
        set_name("Book of Player Rules");
        set_alias("book");
        set_short("Book of Player Rules");
        set_long("This is the book of player rules. Opening the book might \
be the best course of action. It is slightly dog-eared from use.\n");
        set_weight(1000);
        set_pages(11);
        set_book("/room/player/sheriff_book/page");
    }
}
