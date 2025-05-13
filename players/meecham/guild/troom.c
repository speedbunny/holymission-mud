inherit "/guild/guild_room";
#define GM "/guild/master"

int num;

void reset(status arg) {
  ::reset(arg);
  if (arg) return;
  move_object(clone_object("/boards/druid_guild"), this_object());
  num = GM->query_number("druid");
  set_guild(num);
  short_desc = "Druid guild";
  long_desc =
    "You are in the main guild room of the druids.  It seems\n\
much larger than the tree that houses it.  This place must be\n\
of a magical nature as you notice exits from the room that\n\
should really be outside the tree.  You sense you have several\n\
options here:\n\n\
     advance\n\
     list < all/long/# >\n\
     join\n\n";
  items = ({ "tree", "The guild is inside a tree.." });
  property = ({ "no_sneak", "no_steal", "no_fight" });
  dest_dir = ({
    "/players/patience/tree_city1/irowan", "down",
    "/room/church", "church"
  });
}

void add_init() {
  add_action("_start", "start");
}

status _start(string str) {
  switch(str) {
    case "guild":
      this_player()->start_in_guild(1);
      write("Ok, you will now start in the guild.\n");
      break;
    case "church":
      this_player()->start_in_guild(0);
      write("Ok, you will now start in the church.\n");
      break;
    default:
      write("You can only choose to start in the guild or the church.\n");
      break;
  }
  this_player()->save_me(1);
  return (1);
}

status do_join() {
  if (::do_join()) return (1);
  "/sys/chatd"->do_chat(num, this_player()->query_name() +
    " is now a follower of nature!\n");
  this_player()->set_guild(num);
  log_file("GUILD.JOIN", this_player()->query_name() + " joins the druids" +
    " at " + ctime(time()) + "\n");
  return (1);
}

int query_maxhp(int i, int lglvl) {
  return (this_player()->query_con() * 14 +
          this_player()->query_legend_level() * 30 +
          20);
}

int query_maxsp(int i, int lglvl) {
  return (this_player()->query_int() * 12 +
          this_player()->query_wis() * 8 +
          this_player()->query_level() * 2 +
          this_player()->query_legend_level() * 10 +
          40);
}
