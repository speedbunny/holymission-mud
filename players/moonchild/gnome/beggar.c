inherit "obj/monster";

status given;

reset(arg) {
  given=0;
  ::reset(arg);
  if(arg) return;
  set_name("beggar");
  set_race("gnome");
  set_short("A sad looking beggar gnome");
  set_long("This is clearly a gnome at the end of his tether.\n");
  set_level(1);
  set_hp(30);
  set_whimpy(90);
  set_ep(100);
  set_ac(0);
  set_wc(4);
  load_chat(10, ({ "Beggar coughs up some blood.\n",
	"Beggar moans quietly.\n", "Beggar sighs deeply.\n",
	"Beggar says: Do you have any money?\n" }));
  load_a_chat(20, ({ "Beggar looks terrified.\n" }));
  move_object(this_object(),"players/moonchild/gnome/alley1");
}

add_money(arg) {
  if(arg) {
    tell_room(environment(this_player()),"Beggar says: Thank you kind " +
	({ "Creature", "Sir", "Madam" })[this_player()->query_gender()]
	+ ".\n");
    if(!given) {
      object c;
      write("Beggar whispers to you: I have a present for you.\n");
      say("Beggar whispers something to " + this_player()->query_name() + ".\n",
	this_player());
      c=clone_object("players/moonchild/gnome/crystal");
      c->set_type(0);
      if(transfer(c,this_player())) {
	move_object(c,environment());
	tell_room(environment(this_player()),"Beggar drops the crystal.\n");
      } else {
	write("Beggar gives crystal to you.\n");
	say("Beggar gives crystal to " + this_player()->query_name() + ".\n",
		this_player());
      }
      given=1;
    }
  }
  money+=arg;
  return 1;
}
