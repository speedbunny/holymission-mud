inherit "obj/container";
#include "lw.h"
inherit "obj/armour";

void reset(int arg){
    container::reset(arg);
    armour::reset(arg);
    if(arg) return;
    set_name("cloak");
    set_alias("vagcloak");
    set_short("Cloak of Time and Space. (worn)");
    set_long(
      "This is the legandary 'Cloak of Time and Space', and seems to be\n"+
      "phasing with in the space/time continium.   The fibers of the\n"+
      "cloak were woven by the Ancient Timelords of the 4th dimension.\n"+
      "\n");
    set_ac(2 + this_player()->query_legend_level()/3);
    set_weight(0);
    set_max_weight(this_player()->query_level()+2);
    set_value(0);
    set_size((int)this_player()->query_size());
    set_type("guild");
}



void init(){
    armour::init();
    container::init();
}

int drop(string str){
    if(id(str)){
	write("You do not want to drop your cloak.\n");
	return 1;
    }
}

int remove(string str){
    if(id(str)){
	write("You remove your cloak of time and space.\n");
	move_object(clone_object("/players/nylakoorub/guild/obj/nocloak.c"),
	  this_player());
	destruct(this_object());
	return 1;
    }
}



