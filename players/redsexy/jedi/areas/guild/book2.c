inherit "/std/obj/book";

void reset(int iArg){
    ::reset(iArg);
    if(!iArg) {
        set_name("bound in black, a book entitled 'How to Kill Friends and Mutilate People'");
        set_alias("how");
        set_short("How to Kill Friends and Mutilate People\n");
        set_long("This is a book entitled 'How to Kill Friends and Mutilate People' \
If you 'open how', you will probaby be able to read it.\n");
        set_weight(1000);
        set_pages(5);
        set_book("/players/mangla/guild/book2/page");
    }
}
