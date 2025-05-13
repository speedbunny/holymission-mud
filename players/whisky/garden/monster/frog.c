inherit "obj/monster";

    reset(arg) {
    ::reset(arg);
    if(!arg) {

    set_name("whisky");
    set_alt_name("frog");
    set_alias("whisky the frog");
    set_short("Whisky, the frog");
    set_long("A little cute frog.... maybe a prince,\n"+
    "waiting for his princess to kiss him\n");
    set_gender(1);
    set_level(1);
    set_whimpy(100);
    set_al(1000);
    load_chat(20,({
    "Quaaaaakkk\n"}));
    }
  }

    init() {
    add_action("kiss","kiss");
    ::init();
    }
    kiss(arg) {
    if(arg!="frog" && arg!="whisky" && arg!="whisky the frog") return;
    write("Qaaaak\n");
    say("Suddenly a miracle happens as "+this_player()->query_name()+
     " kissed Whisky, the frog\n");
    this_player()->frog_curse(1);
    return 1;
    }
