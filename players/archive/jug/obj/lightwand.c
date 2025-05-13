/* Matt 7-8-93: Revamp */

string short_desc;
status is_lighted;

reset(arg) {
  if(arg) return;
  short_desc = "A sparkling wand";
}

id(str)
{
  return str == "wand" || str == "sparkling wand";
}

short() {
  return short_desc;
}

long() {
  write("This wand seems to have strange power.\n");
  write("There are strange runes on it.\n");
  if(is_lighted)
    write("The wand gleams in all colors of the rainbow.\n");
}

get() { return 1; }
query_value() { return 300; }
query_weight() { return 1; }

init() {
  add_action("read", "read");
  add_action("brightness", "brightness");
  add_action("darkness", "darkness");
}

read(str) {
  if(!id(str) && str != "runes")
    return;
  write("You can see: A sun or a moon (or something like that) ...\n" +
	"and there are two words you can read ... (maybe)\n" +
	"`darkness` and `brightness`. What does this mean ... ?\n");
  return 1;
}

brightness() {
  int i;
  if (is_lighted) {
    write("The wand cannot make more light than they does now.\n");
    return 1;
  }
  i = this_player()->query_spell_points();
  if (i < 10) {
    write("To low on spell points.\n");
    return 1;
  }
  this_player()->restore_spell_points(-10);
  is_lighted = 1;
  call_out("out_of_magic", 4000);
  i = set_light(20);
  if (i > 0 && i <= 20) {
    write("You can see again.\n");
    say(this_player()->query_name() +
	"lights a wand.\n");
  }
  else
    write("Ok.\n");
  return 1;
}

darkness() {
  int i;
  
  if (!is_lighted)
    return;
  i = remove_call_out("out_of_magic");
  is_lighted = 0;
  if (set_light(-20) <= 0) {
    write("It turns dark.\n");
    say(this_player()->query_name() +
	" extinguishes the only light source.\n");
  }
  else {
    write("Ok.\n");
  }
  return 1;
}

out_of_magic() {
  if (set_light(-20) <= 0) {
    say("There is darkness as the wand goes dark.\n");
    write("There is darkness as the wand goes dark.\n");
  }
  else {
    say("The wand goes dark.\n");
    write("The wand goes dark.\n");
  }
  is_lighted = 0;
}
