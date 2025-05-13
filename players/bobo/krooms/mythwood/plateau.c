inherit "room/room";


int read(string str) {

    if(str!="sign") return 0;
    write("It reads: Go this direction.\n");
    return 1;
}

void reset(int arg) {

    if (arg) return;
    set_light(1);
    short_desc="A plateau";
    long_desc="A large rocky plateau.\n"+
              "All around you are steep and unclimbable rocks.\n"+
              "There is a sign pointing southwest.\n";
    dest_dir=({
		"players/bobo/krooms/mythwood/bridge","east",
		"players/bobo/krooms/mythwood/plateau1","southwest",
             });
   items=({
           "sign","Maybe you can read it",
         });
}

void init() {

    ::init();
    add_action("read","read");
}

