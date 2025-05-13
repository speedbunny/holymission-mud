inherit "/obj/monster";

#include "/players/haplo/defs.h"
object knife;
string chats;
get_chats() {
    if(!chats) {
	chats=allocate(3);
	chats[0] =("Hugh says: Hey you like to live dangerously? \n");
	chats[1] =("Hugh says: Maybe you want to buy a license to kill? \n");
	chats[2]=("You can buy a PK license here, If you dare. Hahahahaha \n");
    }
    return chats;

}
reset(arg){
    ::reset(arg);
    if(arg)
	return 1;
    set_name("Hugh the Hand");
    set_race("human");
    set_alias("hugh");
    set_level(100);
    set_gender(1);
    load_chat(4, get_chats());
    set_short("Hugh the Hand");
    set_long("Hugh the Hand is a renowned member of the Brotherhood of the Hand one \n"+
      "of the most feared Assassin guilds in the land. Attacking him will guarantee \n"+
      "your death, of that you are sure. He is dressed entirely in black. His \n"+
      "beard is black and falls in two tightly braided strands. You can see a \n"+
      "bone handled knife sticking out of the black sash around his waist. \n");


    knife=clone_object("/players/haplo/pk/bone_knife");
    transfer(knife,this_object());
    command("wield knife");


}


init(){
    ::init();
    AA("pk_buy","buy");

}

pk_buy(str) {

    if(this_player()->query_money()<5000) {
       notify_fail("You do no thave the money!\n");
        return 0;
    }

    if(str == "license" && (this_player()->query_level()>4)) {
	(this_player()->add_money(-5000));
	(this_player()->add_exp(-5000));
	(this_player()->set_pk());
	return 1;

    }
    if(!str){
     notify_fail("Buy what?\n");
    return 0;
     }

    else {

       notify_fail("Your not qualified to get a PK license!\n");
    return 0;
    }

}
