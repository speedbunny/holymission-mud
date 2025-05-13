inherit "/obj/armour";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("witchrobe");
     set_type("cloak");
     set_ac(1);
     set_short("A Witchrobe");
     set_long("A red Witchrobe with a big pocket, it has the magical power to\nprotect the Witch from enemies.\n");
     set_alias("pocket");
     set_value(200);
  }
}


long(str) {
  if (str==alias) {
     write("You see a little bulg at the pocket.\n");
     return 1;
  }
  ::long(str);
}
 
init() {
  ::init();
   add_action("search","search");
}

search(str) {
string name;

  if (str!="pocket") {
    write("You are on the right way, but you are searching on the false place.\n");
    say(this_player()->query_name()+ " searches around and looks very confused.\n");
    return 1;
  }

  name=this_player()->query_name();
  write("Yep, you find a small iron key.\n" +
	"Suddenly your Witchrobe crumles to ashes.\n");
  say(name+" searches around and finds suddenly a small key.\n" +
      name+"'s Witchrobe crumbles to ashes.\n");
  move_object(clone_object("players/whisky/garden/obj/quest_key"),this_player());
  move_object(clone_object("players/whisky/garden/obj/gras"),this_player());
  this_object()->set_short(0);
  this_player()->stop_wearing(this_object()); 
  destruct(this_object());
  return 1;
}
query_monk_wear() { return 1; }
query_mage_wear() { return 1; }
