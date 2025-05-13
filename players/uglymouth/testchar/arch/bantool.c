/*
 * The master banisher
 * This is not a tool in the proper sense of the word.
 * Don't try to clone or manilulate it.
 */
#define WARNING_DIR	"/banish/warning/"

static string *sheriffs;
string time, sheriff, ban_reason;

int id(string str) {
  return str == "banisher";
}

void reset(int arg) {
  if(arg) return;
  sheriffs = ({ "colossus", "dice", "acdc", "muzmuz" });
}

void init() {
  if(sizeof(explode(file_name(this_object()), "#")) != 1)
    destruct(this_object());
}

int query_sheriff(string name) {
  return member_array(name, sheriffs) != -1 ||
    find_player(name)->query_archwiz();
}

int do_banish(string player, string reason) {
  object pl_obj, *inv;
  int i;
  if(!player || !reason) return 0;
  if(explode(file_name(previous_object()), "#")[0] != "obj/banish") return 0;
  sheriff = this_player()->query_short_name();
  ban_reason = reason;
  time = ctime(time());
  if(pl_obj = find_object(player)) {
    pl_obj->save_me(1);
    tell_object(pl_obj, "You are now banished by " + sheriff
      + " for " + reason + ".\n");
    inv = deep_inventory(pl_obj);
    for(i=0; i<sizeof(inv); i++) destruct(inv[i]);
    destruct(pl_obj);
  }
  save_object("/banish/" + player);
  write_file(WARNING_DIR + player, time + "\n"
    + "Banished by " + sheriff + " for " + ban_reason + ".\n");
  return 1;
}

int do_unbanish(string player, string reason) {
  if(explode(file_name(previous_object()), "#")[0] != "obj/banish") return 0;
  sheriff = this_player()->query_short_name();
  ban_reason = reason;
  time = ctime(time());
  rm("/banish/" + player + ".o");
  write_file(WARNING_DIR + player, time + "\n"
    + "Unbanished by " + sheriff + " for " + ban_reason + ".\n");
  return 1;
}

int do_warn(string player, string reason) {
  object pl_obj;
  if(explode(file_name(previous_object()), "#")[0] != "obj/banish") return 0;
  sheriff = this_player()->query_short_name();
  time = ctime(time());
  pl_obj = find_player(player);
  if(!pl_obj)
    printf(capitalize(player) + " is not on.\n"
      + "Don't forget to mail him your decision.\n");
  else tell_object(pl_obj,
    "You now have received an OFFICIAL warning from " + sheriff + ".\n"
    + "Reason: " + reason + ". Be extra careful now!\n");
  write_file(WARNING_DIR + player, time + "\n"
    + "Officially warned by " + sheriff + " for " + reason + ".\n");
  return 1;
}
