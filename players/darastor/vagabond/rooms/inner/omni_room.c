inherit "room/room";
#include "/players/nylakoorub/guild/defines.h"
#define OMNI_POINT  5
#define PATH   "/players/nylakoorub/guild/"
#define VERSION_FILE  PATH+"lib/checks/omni_version.c"


object omni;


get_new_omni() {
    move_object(clone_object(
	"/players/nylakoorub/guild/obj/omni/lib/omni"),
      this_player());
}




reset(arg) {
    if(arg) return;
    set_light(1);
    short_desc = "Omni Shop";
    long_desc =
    "    You have entered the Omni shop, where you can get points\n"+
    "for your Omni at a cost.  Also you should recieve a new Omni\n"+
    "if your current one is outdated or gives you a Omni if you don't\n"+
    "have one.\n"+
    "\n"+
    "Type 'buy <number>' or 'buy <max>' to purchase Time points.\n"+
    "Cost of each Time Point is: "+OMNI_POINT+
    " coins.\n"+
    "\n";

    dest_dir = ({
      "/players/nylakoorub/guild/rooms/inner/inner_room", "east",
    });
}



init() {
    int version, oldpoints;
    omni = present("omni", this_player());
    add_action("east","east");
    add_action("buy","buy");
    if(omni) {
	version = omni->query_ver_num() != (VERSION_FILE)->query_cur_ver();
	if(version) {
	    tell_object(this_player(),
	      "=============ATTENTION===============\n"+
	      "You're Omni has been updated!\n"+
	      "All points stored were transfered into coins at: "+
	      OMNI_POINT+" coins a point.\n"+
	      "=====================================\n"+
	      "\n");
	    oldpoints = omni->query_omni();
	    this_player()->add_money(oldpoints * OMNI_POINT);
	    do_vag_log("omniupdate",
	      capitalize(this_player()->query_real_name())+
	      " updated "+
	      this_player()->query_possessive()+
	      " Omni from ver. "+
	      omni->query_ver_num()+" to "+
	      "ver. "+
	      (VERSION_FILE)->query_cur_ver()+
	      " on "+
	      ctime(time())+
	      "\n"+
	      "(tranfered "+omni->query_omni()+
	      " points at "+OMNI_POINT+
	      " coins per point, total = "+
	      OMNI_POINT * omni->query_omni()+
	      " )"+
	      "\n");
	    destruct(omni);
	    get_new_omni();
	    return 1;
	}
    }
    if(!omni &&
      this_player()->query_guild() == 10 &&
      !this_player()->query_immortal() ) {
	tell_object(this_player(),
	  "=========ATTENTION==========\n"+
	  "You have just recieved your Omni.\n"+
	  "============================\n"+
	  "\n");
	do_vag_log("omninew",
	  capitalize(this_player()->query_real_name())+
	  " recieves "+this_player()->query_possessive()+
	  " Omni (version "+
	  (VERSION_FILE)->query_cur_ver()+" ) on "+
	  ctime(time())+"\n");
	get_new_omni();
	return 1;
    }


}

east() {
    move_object(this_player(),
      "/players/nylakoorub/guild/rooms/inner/inner_room");
    command("look", this_player());
    return 1;
}


buy(arg) {
    int amount, diff;
    object omni;
    omni = present("omni", this_player());
    if(this_player()->query_guild() != 10 ) {
	write("You are not a member of the Vagabonds guild.\n");
	return 1;
    }
    if(omni) {
	diff = omni->query_max_omni() - omni->query_omni();
	if(diff == 0 ) {
	    write("Your Omni is already full.\n");
	    return 1;
	}
	if(arg == "max") {
	    if(diff <= this_player()->query_money() / OMNI_POINT)
		command("buy "+diff, this_player());
	    else command("buy "+(this_player()->query_money() / OMNI_POINT),
		  this_player());
	    return 1;
	}
	if(arg && sscanf(arg, "%d", amount)) {
	    if(amount <= 0) {
		write("You may only buy a positive amount.\n");
		return 1;
	    }
	    if(amount > this_player()->query_money() / OMNI_POINT) {
		write("You do not have enough money.\n");
		return 1;
	    }
	    if(amount > diff) amount = diff;
	    this_player()->add_money( - (amount * OMNI_POINT));
	    omni->add_omni(amount);
	    write("You buy "+amount+" Time points for your Omni at "+
	      OMNI_POINT +" coins per point,\n"+
	      "for a total of "+ amount*OMNI_POINT +" gold coins.\n");
	    do_vag_log("omnibuytp",
	      capitalize(this_player()->query_real_name()) +
	      " buys "+ amount +" timepoints "+
	      "at "+
	      OMNI_POINT + " coins per point, for a \n"+
	      "total of "+ amount*OMNI_POINT +" gold coins. "+
	      ctime(time())+"\n");
	    say(capitalize(this_player()->query_real_name())+
	      " buys Time points for "+
	      this_player()->query_possessive()+
	      " Omni.\n");
	    return 1;
	}
	write("Buy what?\n");
	return 1;
    }
}





