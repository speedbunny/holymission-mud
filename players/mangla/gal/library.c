
#define TP this_player()
#define TPQ TP->query_name()

inherit "room/room";

reset(arg) 
{

        if (arg) return;

set_light(1); 
short_desc = "Library"; 
long_desc = "This huge room is Etmol's library. The room is filled with\n"+
            "shelves from wall to wall and from floor to ceiling, and the\n"+
            "shelves are filled with hundreds of thousands of books on every\n"+
            "imaginable topic.\n";
            
items = ({
          "books", "Books of all kinds"
        
});
dest_dir=({
          "/players/etmol/workroom", "home"
        });
}

init()
{
add_action("read", "read");
::init();
}
read()
{
write("You read some pages from a book.\n");
write("You feel much wiser.\n");
say(TPQ+" reads some pages from a book.\n");
return 1;
}
