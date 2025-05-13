/* 04-FEB-94 Galadriel: helpfile now in misc/guild, guild dir secured */
/* 05.30.94 Airborne: Changed to new directory. */

#define TP      this_player()
#define GM      "guild/master"
#define GS(x)   (int)this_player()->get_skill(x)[0]
#define COST(x) x==100 ? "Not possible" : x*95 + x*x*5 + 400

inherit "guild/room";
inherit "room/room";

void reset(int arg) {
  if(arg)
    return 0;
  move_object("players/airborne/guild/board", this_object());
  set_light(1);
  set_guild(11);
  short_desc="Barbarians' Guild Hall";
  long_desc="This is the hall of the Barbarians' Guild. It's built, not unsurprisingly,\n"
	+ "entirely out of stone, and is actually a rather imposing structure. There are\n"
	+ "a number of messages carved on the walls here, for the guild members to read.\n"
	+ "To the southwest a brightly lit passage leads off to the temple of the God\n"
	+ "Alit. A dark passage leads southeast, leading to the temple of the Goddess\n"
	+ "Tamara.\n"
	+ "Commands: cost, train, advance, guildinfo, join,\n"
	+ "          list, list [number], list all, list long.\n";
  dest_dir=({ "players/moonchild/pot/orc4", "north",
	"players/airborne/guild/alit_temple", "southwest",
	"players/airborne/guild/tamara_temple", "southeast" });
}

void init() {
  "guild/room"::init();
  "room/room"::init();
  add_action("train_skills", "train");
  add_action("guild_info", "guildinfo");
}

int do_cost() {
  int av_exp;
  if((int)TP->query_guild()!=11) {
    write("You are not a member of this guild.\n");
    return 1;
  }
  av_exp=(int)TP->query_exp() - (int)GM->query_exp((int)TP->query_guild(),
	(int)TP->query_level());
  write("You have " + (av_exp > 0 ? "" + av_exp : "no")
	+ " experience available to raise your abilities.\n");
  write("Cost to raise combat........");
  write(COST(GS("barbarian_combat")));
  write("\n              melee.........");
  write(COST(GS("barbarian_melee")));
  write("\n              fortitude.....");
  write(COST(GS("barbarian_fortitude")));
  write("\n              speed.........");
  write(COST(GS("barbarian_speed")));
  write("\n");
  return (int)::do_cost();
}

int train_skills(string str) {
  int av_exp;
  mixed adv_cost;
  int tmp;
  if((int)TP->query_guild()!=11) {
    write("You are not a member of this guild.\n");
    return 1;
  }
  if(str!="combat" && str!="melee" && str!="fortitude" && str!="speed") {
    notify_fail("Train what?\n");
    return 0;
  }
  av_exp=(int)TP->query_exp() - (int)GM->query_exp((int)TP->query_guild(),
	(int)TP->query_level());
  tmp=GS("barbarian_" + str);
  adv_cost=COST(tmp);
  if(stringp(adv_cost)) {
    write("You can't advance that skill any further.\n");
    return 1;
  }
  if(tmp>(int)TP->query_level() * 5) {
    write("You will have to advance to a higher level before you can advance this skill.\n");
    return 1;
  }
  if(av_exp < adv_cost) {
    write("You don't have enough experience to raise this skill.\n");
    return 1;
  }
  this_player()->add_exp(-adv_cost);
  tmp++;
  GM->change_skill(TP, "barbarian_" + str, tmp, 100, 11);
  if(str=="fortitude")
    TP->set_con((int)TP->query_con());
  else
    if(str=="speed")
      TP->update_speed();
  write("Skill raised.\n");
  return 1;
}

int guild_info() {

/* 04-FEB-94 Galadriel: help in misc/guild now */
  this_player()->more_string(read_file("/players/moonchild/misc/guild/help"));
  return 1;
}

int do_join() {
  if(!::do_join())
    return 1;
  switch((string)this_player()->query_race()) {
    case "elf":
    case "hobbit":
      write("Sorry, but you are of too wimpy a race to become a barbarian.\n");
      return 1;
      break;
  }
  switch((string)this_player()->query_religion()) {
    case "Alitist":
    case "Tamaran":
      this_player()->set_n_wc(3);
      this_player()->set_guild(11);
      "players/airborne/guild/soul"->send_mess("<= Barbarians => "
	+ (string)this_player()->query_name() + " joins the guild!\n");
      log_file("GUILD.JOIN", (string)this_player()->query_name() +
	" joins the barbarian's guild at " + ctime(time()) + "\n");
      break;
    default:
      write("You have to worship a barbarian religion to join the Barbarians' Guild.\n");
      break;
  }
  return 1;
}

int query_maxhp(int lvl) {
  return lvl*10 + 40 + 4 * (this_player()->get_skill("barbarian_fortitude") ?
	GS("barbarian_fortitude") : 0);
}

int query_maxsp(int lvl) {
  return lvl*3 + 37;
}
