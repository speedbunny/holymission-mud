inherit "obj/armour.c";

int is_invis, to_long, num_twist;

reset(arg) {
 ::reset(arg);
 if(arg) return 1;
name = "ring";
 alias = "gold ring";
 size = 0;
 type = "ring";
 short_desc = "A Gold Ring";
 value = 1000000;
 weight = 1;
 ac = 0;
 to_long = 0;
 is_invis = 0;
 num_twist = 0;
}

long() {
  write("This is a solid gold ring. It seems warm to the touch.\n");
if(!worn)
  write("You can see some writing on the inside of the ring.\n");
  return 1;
}

query_info() {
	write("This ring seems to have some type of magic about it.\n");
	write("type 'twist ring' to activate it.\n");
	return;
}

init() { 
 ::init();
 if(environment() != this_player()) return 1;
 add_action("do_read"); add_verb("read");
 add_action("do_twist"); add_verb("twist");
}

drop(silently) {
  if(is_invis)
    do_twist(name);
  ::drop(silently);
  return 0;
}

remove(str) {
 if(is_invis)
   do_twist(name);
 if(::id(str)) {
 ::remove(str);
 return 1;
 }
}

do_read(str) {
 if(::id(str)) {
  if(!worn) {
	write("You can make out the words:\n  t***t *e\n");
	return 1;
    }
  write("Your finger is in the way.\n");
  return 1;
 }
}

do_twist(str) {
  if(!worn || !worn_by) {
       write("You twist the ring in the palm of your hand. Nothing happens.\n");
       return 1;
  }
  if(is_invis) {
worn_by->set_vis();
	write("You fade back into view.\n");
	say(call_other(worn_by,"query_name")+" suddenly appears!\n");
	if(worn) call_out("worn_long", 420);
	is_invis = 0;
	return 1;
  }
  if(num_twist > 15) {
	write("The ring glows with a blinding radiance, then fades!\n");
	say(worn_by->query_name()+" suddenly glows brightly, then fades!\n");
	remove(str);
 	remove_call_out("worn_long");
	destruct(this_object());
	return 1;
  }
  if(!is_invis) {
worn_by->set_invis();
	write("Your body takes on a strange transparancy.....\n");
	say(call_other(worn_by,"query_name")+" twists a ring on their finger and");
	say(" disappears from view!\n");
	is_invis = 1;
	num_twist++;
 	remove_call_out("worn_long");
	return 1;
   }
 write("Twist What?\n");
 return 1;
}

worn_long() {
  if(worn) set_heart_beat(1);
  remove_call_out("worn_long");
}

heart_beat() {
  if(!worn) set_heart_beat(0);
  if(worn_by && to_long == 3) {
    tell_object(worn_by,"The ring of invisibility sap's your strength!\n");
    worn_by->add_spell_points(-1);
    to_long = 0;
  }
  to_long ++;
}
