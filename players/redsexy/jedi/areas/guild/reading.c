inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "The Jedi Reading Room.";     
        long_desc = "\
This room is full of books!  Rows and rows of shelves line the walls and \
each shelf must hold about a hundred volumes.  The Jedi are a learned guild \
and this is their reading room, where they come to study matters relating to \
the guild and conduct in the realms.  Two books in particular grab your attention. \n\n";

        dest_dir = ({
            "/players/mangla/guild/corridor1",  "west",
        });


         items = ({
             "room", "The Jedi Reading room, filled with books",            
             "rows", "There are many rows of shelves",
             "shelves", "Dusty shelves with books on",       
             "books", "Hundreds line the shelves, but only two are in a language you understand",
             "volumes", "Volumes of books.",
        });

         clone_list = ({

           1, 1,"force","players/redsexy/jedi/areas/guild/book1",0,
/* cannot get two book in same room to function properly - Redsexy Feb97 
           2, 1,"how","players/redsexy/jedi/areas/guild/book2",0, */


         });

    }
    ::reset(arg);
    replace_program("room/room");
}


