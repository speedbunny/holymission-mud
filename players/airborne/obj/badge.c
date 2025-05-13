inherit "obj/armour";

#define TP this_player()
#define TPN TP->query_name()
#define TPPN TP-query_possesive()


reset(arg) {
  ::reset(arg);
  if(arg) return;
	set_name("badge");
	set_alias("badge of  the Baal-Rog slayer");
	set_short("Badge of the Baal-Rog slayer");
	set_type("badge");

	}
init() {
   ::init();
   add_action("fix", "fix");
   add_action("show", "display");
   add_action("show", "show");
	}

show(str) {
   if(!id(str)) return;
	write("You display your badge proudly.\n");
	say( TPN+ " shows off the badge of the Baal-Rog slayers.\n");
		return 1;
	}

fix(str) {
   if(str !="title") return;
	title_set();
	write("You have fixed your title.\n");
     return 1;
	}

title_set() {
object x;
   x=environment(this_object());
	if(!x) return;
	x->set_title("Baal-Rog slayer");
	x->set_pretitle("none");
		return 1;
	}

query_weight() { return 0; }

query_auto_load() { return "players/airborne/obj/badge:"; }


long() {
write("It is a bright and shining badge. Everyone is sure to envy you because\n"
  +"of it, and because you killed the Baal-Rog. To adjust your title just\n"
  +"type 'fix title'. To show everyone your badge use 'show badge'.\n"); }

remove() { 
	write(" You decide to save it to show your grandchildren instead.\n"); 
	return 1;
	}

dest() { destruct(this_object()); }

drop() { 
  if (query_verb()== "sell"){
	write ("You decide not to sell it and save it for your grandchildren.\n");
	return 1;
		}
  if(query_verb() == "give"){
	write("You change your mind and decide to say it for you grandchildren.\n");
	return 1;
	}

   write("It is to pretty to drop.\n");
   return 1;
}
