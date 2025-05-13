inherit "/std/obj/book";

reset(arg){
   set_name("Book of Wizard Rules");
   set_alias("book");
   set_short("Book of Wizard Rules");
   set_long("This is the book of wizard rules. " +
            "Opening the book might be the best course of action. "+
            "It is slightly dog-eared from use.\n");
   set_weight(10000);
   set_pages(11);
   set_book("/room/wiz/sheriff_book/page");
}
