inherit "obj/monster";
string chats;
reset(arg) {
    ::reset(arg);
    if(!arg) {
        set_name("spider");
        set_race("spider");
        set_short("spider");
        set_long("This little creepy spider is looking at you!!\n");
	set_level(1);
	set_al(1000);
	set_ac(1);
   set_wc(0);
	if (!chats) {
            chats=allocate(3);
   chats[0]="The spider creeps up your leg!!\n";
   chats[1]="The spider crawls all over you!!\n";
    chats[2]="The spider crawls down your back!!\n";
	}
        load_chat(10,chats);
    }
}

   /* Based on original code by Tuppence */
