/* 04-FEB-94 Galadriel: helpfile now in misc/guild, guild dir secured */
/* 05.30.94 Airborne: Changed to new directory. */

#define TP      this_player()
#define GM      "guild/master"

#define GS(x)   (int)this_player()->get_skill(x)[0]

#define COST(x) x==100 ? "Already Bestest" : x*95 + x*5+400

inherit "guild/room";
inherit "room/room";

void reset(int arg) {
  if(arg) return 0;

  set_light(1);

  short_desc = "Barbarians' Training Room";

  long_desc = "This is the training room of the Barbarians' Guild. It's \n" +
	      "built not unsurprisingly entirely out of stone, and it is \n" +
              "actually a rather imposing structure. You can see all around\n" +
	      "you tools, weapons, armor, and such to aid you in your \n" +
	      "training. \n" +
	      "	\n" +
	      "Commands: cost and train. \n" +
	      "	\n";

  dest_dir=({
		"/players/apollo/guild/room", "east",
	});
}

void init() {
  "room/room"::init();

  add_action("do_cost", "cost");
  add_action("train_skills", "train");
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
  return 1;
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
  this_player()->add_exp(-adv_cost);
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

// Whisky: the hit_points of the barbarian raise + 4 per legend level
int query_maxhp(int lvl) 
{
   int lg;

 
    return ((lvl*14+40)+6*
          (this_player()->get_skill("barbarian_fortitude") ?
	        GS("barbarian_fortitude") : 0));
}
