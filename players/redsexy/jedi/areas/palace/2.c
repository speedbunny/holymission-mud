inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "The larder room of Jabba's palace.";     
        long_desc = "\
You have now entered the larder in Jabba's palace, where lots of cans and packages \
of food are stored.  Arranged in shelves, you doubt you have even heard of one of \
these items, and remembering what Hutts like to eat, you avoid consuming any of it.\n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/1",  "west",
            "/players/redsexy/jedi/areas/palace/4", "south",

        });


         items = ({
             "shelves", "The shelves are filled with cans and packages",            
             "larder", "The room is an enormous store for Jabba's food",
             "cans", "The only names you recognise are 'Toadspittle' and 'Dogcrap', so you do not eat any of it!",       
             "packages", "Lots of boxes and cans around the larder",
        });
    }
    ::reset(arg);
    replace_program("room/room");
}


