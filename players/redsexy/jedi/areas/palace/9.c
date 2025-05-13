inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "The reading room of Jabba's Palace";     
        long_desc = "\
The walls are lined with shelves of books in here, and desks are set in rows so people \
can study in peace and quiet.  Not as if Jabba allows his employees study leave, the \
workers who come in here are undoubtedly trying to please Jabba in some way by \
researching the latest cocktails or learning the latest jokes.  It is very unlikely \
anyone gets to read for pleasure whilst Jabba is the boss.\n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/8",  "west",
        });


         items = ({
             "walls", "The walls are lined with bookshelves",            
             "shelves", "Rows upon rows of books line the shelves.  You could try searching them",
             "books", "They're written in Huttese so you cannot understand them",
             "desks", "Oakwood desks with inkwells cut into them",
        });
    }
    ::reset(arg);
}

void init() {
   ::init();


   add_action("_search","search");

   }

int _search(string str) {
  object ob;


   if(str!="shelves") return 0;
         write("As you search the dusty shelves a book falls into your hands!\n");
         ob=clone_object("/players/redsexy/jedi/objects/book.c");
         transfer(ob,this_player());
         return 1;
}

