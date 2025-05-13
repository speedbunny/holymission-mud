inherit "/guild/guild_room";
#define GM "/guild/master"

int num;

int move(string str) {
    if(!str || str == "")
        str = query_verb(); 
 
    if(str == "west" && this_player()->query_real_guild() != 2 &&
       !this_player()->query_immortal()) {
        write("Sorry, druids only.\n");
        return 1;
    }   
    else
        return ::move(str);
}

void reset(status arg) {
  ::reset(arg);
  if (arg) return;
  move_object(clone_object("/boards/guilds/druid_guild"), this_object());
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
  property = ({ "no_steal", "no_fight", "no_clean_up" });
  dest_dir = ({
    "/players/patience/tree_city1/irowan", "down",
    "/players/shadowmonk/guild/quip_room", "west",
    "/room/church", "church"
  });
}

void init() {
  ::init();
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

void add_init() {
  add_action("_xx","test");
}

status _xx() {
  object ob;
  ob = present("druidsoul", this_player());
  destruct(ob);
  move_object(clone_object("/players/shadowmonk/guild/soul"), this_player());
  write("Ok, soul switched.\n");
  return (1);
}
