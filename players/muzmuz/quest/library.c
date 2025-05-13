inherit "room/room";

void reset (int arg)
{
   if(!arg)
   {

       short_desc = "Library";
        long_desc =
 "You have reached the library of the house. The room is well furnished with\n" +
 "a wooden table and a wooden chair. The smell of old books fills the air.\n" +
 "You also see some shelves with many books on them.\n";

       dest_dir = ({"/players/muzmuz/quest/uphall","north",
                            });

        set_light (1);

         items = ({"table","An old oaken table",
                   "chair","An old oaken chair",
                   "books","There are lots of books. Since you do not see a card\n" +
                           "catalogue, you assume a long search of the shelves would\n" +
                           "be needed to find any useful books",
                   "shelves","The shelves contain many book on many different subjects",
                         });


        }
}


void init()
{
   ::init();
   add_action("fcn_search","search");
}


mixed fcn_search(string arg)
{

    if (!arg)
        return 0;
    else if (arg!="shelves" && arg!="books")
    {
        write("You search around but find nothing.\n");
        return 1;
    }
    else if (find_object("/players/muzmuz/quest/quest_book"))
    {
        write("You search around but find nothing of interest.\n");
        return 1;
    }
    move_object("/players/muzmuz/quest/quest_book",environment(this_player()));
    write("A book falls out of the shelf.\n");
    say(this_player()->query_name()+" found a book.\n",this_player());
   return 1;
}

