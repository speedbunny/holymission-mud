inherit "/obj/treasure.c"

int static loaded;
int static voice;

void reset(int arg) {
     if(arg) return;
     set_name("walkman");
     set_short("a magical sound-reproducer device");
     set_value(0);
     set_weight(0);
     set_long("This is a magic walkman.\nTry <walkhelp> if you "+
              "don't know, how to use it.\n");
}

void init {
     ::init();
     add_action("walkhelp","walkhelp");
     add_action("insert","insert");
     add_action("eject","eject");
     add_action("play","play");
     add_action("settings","settings");
     add_action("loud","loud");
     add_action("low","low");
     add_action("beg","beg");
     add_action("off","off");
}

int walkhelp(string str) {
    if(!str) {
        notify_fail("Pardon?\n");
        return 0;
    }
    write("This is a magic walkman. If you have sound-crystals "+
               "for it, then you're really lucky.\n"+
               "Usage: <insert> crystal in walkman\n"+
               "       <eject> will get the crystal out of the device\n"+
               "       <play> guess what it is for\n"+
               "       <off>  stops playing\n"+
               "       <beg> will start playing from the beginning\n"+
               "       <low> low voice - only you will hear the song\n"+
               "       <loud> everyone in the room will hear the song\n"+
               "       <settings> obvious\n"+
               "We hope, you will enjoy it very much!\n");
    return 1;
}



