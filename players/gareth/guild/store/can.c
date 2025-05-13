inherit "/obj/treasure";

reset(arg) { 
    ::reset(arg);
    if (arg) return;
    
    name = "can";
    alias_name = "trashcan";
    alt_name = "trashcan";
    short_desc = "A Gold Can";
    long_desc = "A very expensive looking gold can.\n" +
                "It looks useful for trashing things.\n";
    }
init() {
    ::init();
    add_action("trash","trash");
    }

trash(arg) {
    if (!arg) return;
    if (!present(arg,this_player())) {
        write("You don't have this item!");
        return 1; 
        }
    destruct(present(arg,this_player()));
    write("Thanks for protecting the environment! \n");
    return 1;
}
get() { return 0; }

