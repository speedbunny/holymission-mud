/* This object was made to allow temporary banishments by the sheriff,
   Ethereal Cashimor, 170393. */

inherit "obj/thing";
#include "/players/haplo/defs.h"

/* Add additional sheriffs in this function: */


static query_may_use() {
string dummy1,dummy2;

  if(!query_ip_number(this_player())) return 0;
  if(sscanf("#haplo#saffrin#sauron#gandalf","%s#"+this_player()->query_real_name()
                  + "#%s",dummy1,dummy2)!=2) return 0;
  return 1;
}

reset(arg) {
  set_name("banisher");
  set_short("A banisher");
  set_long("With this item one can banish and debanish people.\n");
  set_weight(0);
  set_value(0);
  set_can_get(1);
}

init() {
  ::init();
  add_action("banish","banish");
  add_action("debanish","debanish");
}

static banish(who) {
string banished_by,title;

  if(!query_may_use()) {
    write("You're not allowed to use this item!\n");
   destruct(this_object());
    return 1;
  }
  if(!who) {
    write("Banish who?\n");
    return 1;
  }
  if(!this_player()->valid_name(who)) {
    write("Banish who?\n");
    return 1;
  }
  if(restore_object("banish2/" + who)){
    write("That name is already banished.\n");
    return 1;
  }
  banished_by=capitalize(this_player()->query_real_name());
  title=this_player()->query_title();
  save_object("banish2/" + who);
  write(capitalize(who)+" banished!\n");
  return 1;
}

static debanish(who) {
  if(!query_may_use()) {
    write("You're not allowed to use this item!\n");
    return 1;
  }
  if(!who) {
    write("Debanish who?\n");
    return 1;
  }
  if(!this_player()->valid_name(who)) {
    write("Banish who?\n");
    return 1;
  }
  if(!restore_object("banish2/" + who)) {
    write("That name is not banished.\n");
    return 1;
  }
  rm("/banish2/"+who+".o");
  write(capitalize(who)+" debanished!\n");
  return 1;
}

query_auto_load() {
  if(!query_may_use()) return 0;
  return "obj/banish:";
}

drop() {
  return 1;
}

prevent_insert() {
  return 1;
}



