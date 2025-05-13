#include "/players/trout/defs.h"

int level, cost;
string roomname, filepath;


do_spacefold(arg) {
string type, dest;
object who, where;

      sscanf( arg, "to %s %s", type, dest);
     if(ENV(this_player())->short() != "Pocket Dimension"){
	write("You cannot fold space here! Only in a pocket dimension!\n");
	return 1;
	}
     if(!arg){
	write("Useage: spacefold to <type> <destination>\n");
	return 1;
        }
	call_out("_move", 8, filepath);
	call_out("say1", 7, roomname);
	call_out("_say2", 7, filepath);
	MO(CO(YY+"/vag/pocket"), environment());
	write("You open a door to a pocket dimension. From there you can "+
	"fold space!\n");
	say(capitalize(TP()->query_real_name())+" opens a door to a "+
	" pocket dimension!\n");
	return 1;

	}
int _move(string arg) {
     object env, *ob;
     int i, j;


	env= environment(this_player());
	ob = all_inventory(env);
	j = sizeof(ob);
	for(i=0; i<j; i++){
	     MO(ob[i], arg);
	     }
	return 1;
	}

int _say1(string arg){
	write("You finish folding space, and teleport your whole area"+
	" to "+roomname+"!\n");
	return 1;
	}

int say2(string arg){
      	tell_room(arg, "The whole area distorts as "+capitalize(TP()->QRN())+
	" unfolds space here!\n");
	return 1;
	}
