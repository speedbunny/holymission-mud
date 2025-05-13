inherit "/room/room";

int counter;

int do_dig(string str) {
    string msg;
    int    i;
    object ob;

    switch(str) {
        case "for treasure":
// This is how you add treasure to individual rooms...
// Create a function treasure_dig() and have it return 1 if treasure is   
// found. You must handle the msgs in this function as well.
            if(this_object()->treasure_dig()) {
                return 1;
                break;
            }
            else
                write("You may be digging for treasure, but all you seem \
to be able to find is sand.\n");
        case "sand":
            i = (str == "sand"); // Check since we 'fell through'.
            if(counter >= 10) {
                if(!i)	// Arg was 'for treasure'.
                    write("It slips through your hands as you try to get \
it.\n");
                else	// Arg was 'sand'.
                    write("You find some sand, but as you try to get it, \
it slips through your fingers.\n");
                say(this_player()->query_name()+" digs and searches the \
sand.\n");
                return 1;
                break;
            }
          else if(counter != 10) {
                msg = "You find some sand";
                ob = clone_object("/players/redsexy/objects/sand");
                if(transfer(ob, this_player())) {
                    msg += ", but you can't carry that much";
                    destruct(ob);
                }
                counter++;
                msg += ".\n";
                if(i)	// Arg was 'sand'.
                    write(msg);
                say(this_player()->query_name()+" digs and searches the \
sand.\n");
                return 1;
            }
    }
}

void init() {
    ::init();
    add_action("do_dig", "dig");
}
