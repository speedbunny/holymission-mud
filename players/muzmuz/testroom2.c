inherit "room/room";

object ob, mo ;
reset(arg) {

   if(!arg) {

    short_desc = "Muzmuz`s second try.";

     long_desc = "This is Muzmuz`s second try. You are not sure yet\n" +
                 "what you will see here, but you are sure that he\n" +
                 "did his best to make this room nice.\n" +
                 "Well, just start to look at everything you can\n" +
                 "see here, if you survive, thank him.\n";


     set_light(1);

      dest_dir = ({"players/muzmuz/workroom","down",
                   "players/muzmuz/testroom","south"
                 });

      items = ({"guineapig","You see a really cute guineapig",
                "hornet","You see a very dangerous hornet, you better kill it"});

     ob = clone_object ("/players/muzmuz/obj/table.c");
            move_object(ob,this_object());
     mo = clone_object ("players/muzmuz/monster/guineapig.c");
          move_object(mo,this_object());
      }

  }

init()

{
  ::init();
add_action("jaa","ja");

}
int jaa()
{this_player()->set_legend_level(this_player()->query_legend_level()+1);
return 1;
}
