inherit "/room/room";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Bugged room";
    long_desc =
    "If you are in this room it means a bug has occurred. Please note the\n"+
    "appropriate file and the bug message and mail them to Colossus.\n"+
    "If you like you can also use the bug command.\n";
    dest_dir = ({
      "/room/church", "church",
    });
}
