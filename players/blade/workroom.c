inherit "room/room";

object board;

int equip() {
  if(this_player()->query_real_name()=="blade"){
    move_object(clone_object("/players/blade/general/wizcloak.c"),this_player());
    move_object(clone_object("/players/blade/general/wizdagger.c"),this_player());
    return 1;
	      }
  if(this_player()->query_real_name()!="blade") {
    write("You are not Blade!  Go away!");
    return 1;
  }
}

drinkf(str) {
  if(!str) {
    write("Drink what?");
    return 0;
  }
    if(str=="liquor") {
      write(this_player()->query_name() + "takes a long swig from the bottle\n");
      this_player()->heal_self(50);
      return 1;
    }
}

reset(arg) {  
    if(!arg) {
        set_light(1);
        short_desc="A small cave owned by Blade.";
        long_desc=
            "This is a small cave owned by Blade.  In the \n" +
            "corner you notice a small chair, and a cot.  \n" +
            "Surrounding the cot are many open books strewn \n" +
            "haphazardly.  It seems that Blade has been working \n" +
            "very hard at something.  Next to the chair is a \n" +
            "half filled bottle of liquor, so you think he can't \n" +
            "be working too hard... \n";

        items=({
            "bottle","A half filled bottle of cheap vodka",
            "cot","A small bed that doesn't look like it is getting much use",
            "books","A large assortment of books."
            "cave", "A small and slightly dusty cave.",
     "chair", "A small worn chair that looks like its ready to fall apart.",});
        dest_dir=({
            "/players/blade/testroom.c", "test",
            "/players/blade/portal_room.c","north",
                 });
        smell = "This place smells of mouldy old books.";
	move_object((clone_object("/players/blade/box.c")),this_object());
	board = clone_object("/obj/board");
        board->set_name("The stupid shit board");
	board->set_file("/players/blade/stupid_shit");
	move_object(board,this_object());
   }
}

init(){
 ::init();
   add_action("drinkf","drink");
   add_action("equip","equip");
}



















