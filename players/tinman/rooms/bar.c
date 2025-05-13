/* 04-FEB-94 Galadriel: helpfile now in misc/guild, guild dir secured */
/* 05.30.94 Airborne: Changed to new directory. */

#define TP      this_player()
#define GM      "guild/master"

#define GS(x)   (int)this_player()->get_skill(x)[0]

#define COST(x) x==500 ? "Already Bestest" : x*95 + x*5+400
inherit "room/room";
object conan;
inherit "guild/room";

void reset(int arg) {
  if(arg)
    return 0;
  move_object("players/tatsuo/guild/board", this_object());
  set_light(1);
if(!conan){
  move_object(clone_object("/players/tatsuo/guild/conan"),this_object());
}
  set_guild(11);
  short_desc="Barbarians' Guild Hall";
  long_desc="This is the hall of the Barbarians' Guild. It's built, not unsurprisingly,\n"
	+ "entirely out of stone, and is actually a rather imposing structure. There are\n"
	+ "a number of messages carved on the walls here, for the guild members to read.\n"
	+ "Commands: cost, train, advance, guildinfo, join,\n"
	+ "          list, list [number], list all, list long.\n";
  dest_dir=({"players/tatsuo/guild/camp6","east",
	});
}

void init() {
  "guild/room"::init();
  "room/room"::init();
  add_action("train_skills", "train");
  add_action("guild_info", "guildinfo");
  add_action("go_house","house");
   if(this_player()->query_guild()==11 && !TP->query_immortal()){
     this_player()->start_in_guild(1);
     }
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
  write("\n              toughness.....");
  write(COST(GS("barb_toughness")));
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
  if(str!="combat" && str!="melee" && str!="fortitude" && str!="speed" && str!="toughness"){
    notify_fail("Train what?\n");
    return 0;
  }
  av_exp=(int)TP->query_exp() - (int)GM->query_exp((int)TP->query_guild(),
	(int)TP->query_level());
   switch(str){
   case "speed":
   case "melee":
   case "fortitude":
   case "combat":
   tmp=GS("barbarian_"+str);
   break;
   case "toughness":
   tmp=GS("barb_toughness");
   break;
   }
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
  this_player()->add_exp(adv_cost);
  tmp++;
  switch(str){
   case "fortitude":
   case "speed":
   case "combat":
   case "melee":
   GM->change_skill(TP, "barbarian_"+ str, tmp, 100, 11);
   break;
   case "toughness":
   GM->change_skill(TP, "barb_toughness", tmp, 100, 11);
   break;
   }
  if(str=="fortitude")
    TP->set_con((int)TP->query_con());
  else
    if(str=="speed")
      TP->update_speed();
  write("Conan shows you the ways of "+str+".\n");
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
    case "gnome":
    case "hobbit":
    case "elf":
      write("Sorry, but you are of too wimpy a race to become a barbarian.\n");
      return 1;
      break;
  }
  switch((string)this_player()->query_religion()) {
    case "Alitist":
    case "Crom":
	this_player()->set_n_wc(9);
      this_player()->set_guild(11);
      "players/tatsuo/guild/soul"->send_mess("<= Barbarians => "
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

// Whisky: the hit_points of the barbarian raise + 4 per legend level
int query_maxhp(int lvl) 
{
   int lg;

 
    return ((lvl*14+40)+6*
          (this_player()->get_skill("barbarian_fortitude") ?
	        GS("barbarian_fortitude") : 0));
}

int query_maxsp(int lvl) {
  return lvl*3 + 37;
}
go_house(){

TP->move_player("to a lovely house#room/church");
command("house",TP);
}
