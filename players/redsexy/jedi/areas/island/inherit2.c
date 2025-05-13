inherit "/room/room";

int counter, fcounter;

int _dig(string str) {
    string msg;
    object ob;

    if(!str || (str != "sand" && str != "for treasure")) {
        return 0;
    }
    else if(str == "for treasure") {
        str = "sand";
    }

    if(str == "sand") {
        if(fcounter >= 10) {
            write("You find some sand, but as you try to get it, it slips \
through your fingers.\n");
            say(this_player()->query_name()+" digs and searches the \
sand.\n");
            return 1;
        }
        else if (fcounter != 5) {
            msg = "You find some sand";
            ob = clone_object("/players/redsexy/objects/sand");
            if(transfer(ob, this_player())) {
                msg += ", but you can't carry that much";
                destruct(ob);
            }
            else {
                fcounter++;
            }
            msg += ".\n";
            write(msg);
            say(this_player()->query_name()+" digs and searches the \
sand.\n");
            return 1;
        }
        else {
            str = "for treasure";
            fcounter++;
        }
    }

    if(str == "for treasure") {
        if(counter < 1) {
            write("You find nothing!\n");
            say(this_player()->query_name()+"digs and searches the \
sand.\n");
            return 1;
        }
        else {
            counter = 1;
            return 1;
        }
    }
}

void init() {
    ::init();
    add_action("_dig", "dig");
}
