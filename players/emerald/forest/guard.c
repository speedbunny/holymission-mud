inherit "/obj/monster";

object friend;

void reset(int arg) {
  object o;
  ::reset(arg);
  if(arg) return;
  set_name("tower guard");
  set_alias("guard");
  set_level(20);
  set_long("The tower guard looks at you, grinning.\n"
         + "You realise he doesn't really like you very much.\n");
  set_gender(1);
  load_chat(30, ({
    "Tower guard says: Go away!  We don't like your type here.\n",
    "Tower guard sharpens his nails with his sword.\n",
    "Tower guard laughs at you.\n",
    "Tower guard says: Look.  Another of those wimpy adventurers.\n",
    "Tower guard says: I wish this job would bring some challenge for once.\n",
    "Tower guard mutters something about not being paid enough.\n",
    "Tower guard mumbles about the whiskey in the tower bar.\n",
  }));

}
void set_friend(object f) {
  friend=f;
}

mixed hit_player(int dam,int kind,mixed elem) {
  if(friend && !friend->query_attacker(this_player()))
    friend->attacked_by(this_player());
  return (int)::hit_player(dam, kind);
}

int hold(object caller,int time) {
  return 1;
}

void stop_fight() {
  if(this_player()->query_level()>=30)
    ::stop_fight();
}
