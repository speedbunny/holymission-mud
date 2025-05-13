  inherit "/obj/armour";

  void reset(int flag) {
     ::reset(flag);
     if (flag == 0) {

        set_name("A Black Fedora");
        set_alias("fedora");
        set_short("A Black Fedora");
        set_long("This is The Janitor's fedora, it is a symbol of his membership in 'The Family'.\n");
        set_ac(1);
        set_type("armour");
        set_value(10000);
        set_weight(0);
     }
  }

query_auto_load(){ return "/players/beelzebub/personal/fedora2:";} 

init(){
if (this_player()->query_real_name() != "morrolan") { 
        destruct(this_object());
        }
    ::init();
        add_action("no_way", "drop");   add_action("no_way", "give");
}
no_way() {
	write("You couldn't drop that even if you wanted to.\n");
	return 1; }
