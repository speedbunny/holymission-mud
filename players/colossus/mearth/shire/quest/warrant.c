inherit "obj/treasure";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("arrest warrant");
    set_alias("warrant");
    set_alt_name("ARREST_WARRANT");
    set_short("Arrest warrant");
    set_long("An arrest warrant giving the holder the right to\n"+
      "arrest a fugitive.\n");
    set_value(0);
}

status drop(){
    write("You do not want to drop the arrest warrant you worked\n\
so hard to get.\n");
    return 1;
}
