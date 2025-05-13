inherit "room/room";
 
object my, weapon;
int passage_open;
string chat_str, a_chat_str;
 
reset(arg)
{
	if(!arg) {
#if 0 
     ::reset(arg);
     set_outdoors(1);
#endif
     set_light(1);
     long_desc = "Mystic's cave\n\n"+
          "     You have entered the cave of an old wizard,\n" +
          "     he is usually sitting at his table reading\n" +
          "     a book.\n\n";
    short_desc = "The Mystic's cave";
    dest_dir = ({
        "players/animal/light/light4","south",
     });
     items = ({
     "table","This table is old and covered with magic books",
     "books","The books are unusable",
     });
	}
     extra_reset();
     return;
}

realm() { return "NT"; }
 
extra_reset() {
    if (!my || !living(my)) {
     my = clone_object("obj/monster");
    if (!chat_str) {
  chat_str = allocate(4);
  a_chat_str = allocate(4);
  chat_str[0] = "The Mystic says: Looking for something?\n";
  chat_str[1] = "The Mystic says: I have not seen it.\n";
  chat_str[2] = "The Mystic says: Want to see a magic trick?\n";
  chat_str[3] = "The Mystic says: Axe's are hard to find these days.\n";
  a_chat_str[0] = "The Mystic screams!\n";
  a_chat_str[1] = "The Mystic curses!\n";
  a_chat_str[2] = "The Mystic does look happy.\n";
  a_chat_str[3] = "The Mystic says: You will not see the end of me yet!\n";
  call_other(my, "load_chat", 25, chat_str);
  call_other(my, "load_a_chat", 25, a_chat_str);
}
     call_other(my, "set_name", "mystic");
     call_other(my, "set_alias", "wizard");
     call_other(my, "set_level", 19);
     call_other(my, "set_hp", 500);
     call_other(my, "set_ep", 1000000);
     call_other(my, "set_short", "An old mystic");
     call_other(my, "set_wc", 23);
     call_other(my, "set_ac", 11);
	my->set_steal(1);
     call_other(my, "set_al", 1000);
     call_other(my, "set_aggressive", 0);
     call_other(my, "set_chance",35);
     call_other(my, "set_spell_mess1",
                "The mystic waves his arms wildy!");
     call_other(my, "set_spell_mess2",
                "The mystic hits you with his spell.");
     call_other(my, "set_spell_dam",30);
     move_object(my, this_object());
     weapon = clone_object("obj/weapon");
     call_other(weapon, "set_name", "staff");
     call_other(weapon, "set_alias", "staff of beating");
     call_other(weapon, "set_short", "staff of beating");
     call_other(weapon,"set_long",
     "This staff has the word 'prince' imprinted on it.\n");
     call_other(weapon, "set_class", 6);
     call_other(weapon, "set_weight", 3);
     call_other(weapon, "set_value", 5000);
     call_other(weapon, "set_hit_func", this_object());
     move_object(weapon, my);
     call_other(my, "init_command", "wield staff");
    }
}
 
weapon_hit(a)  {
    if (call_other(this_player(), "query_name") == "Mystic" && !random(5)) {
     tell_room(environment(a), "The Mystic yells: LEAVE.\n\n" +
          "You leave in a hurry!\n");
     call_other(a, "run_away", 1);
     return 5;
    }
     if(call_other(a,"id","prince")) {
    tell_room(environment(a), call_other(a, "query_name") +
     " is hit hard by the staff of beating.\n");
     return random(20)+14;
     }else{
          return 12;
     }
}
 
init() {
     ::init();
    add_action("search"); add_verb("search");
    add_action("down"); add_verb("down");
    passage_open = 0;
}
 
long(){
     ::long();
    if (passage_open) write("There is a trap door open leading down\n");
}
 
down(){
    if (!passage_open) return 0;
	if(my && present(my)) {
        write("The Mystic waves his arms wildy and you freeze.\n");
        return 1;
    }
	if(my && !present(my)) {
		write("The mystic has cast a spell on you, you cannot go down.\n");
	return 1;
	}
    call_other(this_player(),"move_player","down#players/animal/cave/1");
    return 1;
}
 
search(str) {
    object ob;
    if (!str) str = "room";
    if (str=="room") {
     if(random(100) > 60) {
 write("A careful search of this place reveals a trap door in the floor!\n");
     say(call_other(this_player(),"query_name") +
     " finds a trap door leading down.\n");
        passage_open=1;
    }else{
     write("You find nothing unusual.\n");
    return 1;
     }
     return 1;
   }
}
query_no_steal() { return 1; }
