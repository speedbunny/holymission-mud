#include "/include/defs.h"

inherit "obj/weapon";

object wielder;

string owner="";

void reset(int arg) {
  ::reset(arg);
  if (arg) return 0;
  set_name("A small dagger");
  set_id("dagger");
  set_alias("t_dagger");
  set_short("A small dagger");
   set_long("An ancient dagger.  It is said to contain the power of\n"+
            "the thief god Mask.  It is the mark of a thief guide, use\n"+
            "its powers wisely.  Type 'gabil' to see what it can do.\n");
  set_class(19);
  set_value(10000);
  set_weight(1);
  set_type(3);
}

set_owner(string arg) {
  owner = arg;
  return 1;
}

void init() {
  ::init();    
  add_action("ban", "ban");
  add_action("gabil","gabil");
  add_action("unban", "unban");
}

int get() {
  if(TP->NAME == owner)
    return 1;
  else {
    write("The dagger destroys itself to avoid being wielded by you.\n");
    say(TP->NAME +
      " tries to pick up the dagger, but the dagger destroys itself.\n",
      TP);
    destruct(TO);
  }
  return 0;
}

int drop() {
  this_player()->stop_wielding();
  write("You suddenly find yourself unable to drop the dagger.\n");
  if(!this_player()->query_legend_level()){
    present("thiefsoul",this_player())->set_righteous(0);
    write("You have fallen from favor, and the dagger fades away.\n");
    destruct(this_object());
    return 1;
  }
  return 1;
}

int wield(string arg) {

  int ret;

  ret = ::wield(arg);
  if(ret && (!wielder)) {
    wielder = TP;
    write("As you wield the dagger, power surges through your body, " +
          "engulfing\nyou in flames!\n");
    say("You see " + TP->NAME +
        " become engulfed in flames as ");
    say(CAP(TP->PRO) + " wields a dagger!\n");
    command("scream", TP);
  }
  return(ret);
}

un_wield(arg) {
  ::un_wield(arg);
  write("You feel the power of the dagger drain out of you.\n");
  say(TP->NAME + " looks a little less powerful.\n");
  command("sigh", TP);
  wielder = 0;
}

int ban(string arg)  {
  object ban_pla, bgs;
  if(!present(arg, ENV(TP))) {
    write(capitalize(arg) + "is not in the room.  You have to be in the same room to banish.\n");
    return 1;
  }
  if(present(arg, ENV(TP))) {
    ban_pla = present(arg, ENV(TP));
    if(ban_pla->IMM) {
      write("You can not ban a wizard from the thieves guild.  If a wiz is\n" +
            "causing a problem mail the GM.\n");
      return 1;
    }
    if(ban_pla->query_real_guild() != 1) {
      write("This player is not a member of the thieves guild.\n");
      return 1;
     }
    bgs = ban_pla->query_guild_soul();
    if(bgs->query_renegade()){
      write("This player is already been branded a renegade.\n");
      return 1;
    }
    if(bgs->query_righteous() == 1){
      write("You can not ban a thief guide, if there is a problem, contact the GM.\n");
      return 1;
    }
    bgs->set_righteous(0);
    bgs->set_renegade(1);
    TELL(ban_pla, "You have been marked as a thief renegade.\n");
    write("You have banned " + CAP(arg) + ".\n");
    return 1;
  }
}
int unban(string arg){
object unban_pla, pgs;
    if(!present(arg, ENV(TP))) { 
       write(capitalize(arg)+ "is not here.  You must be in the same room "+
       "to reinstate their guild powers.\n");
      return 1;
}
  if(present(arg, ENV(TP))) { 
    unban_pla = present(arg, ENV(TP));
    pgs = unban_pla->query_guild_soul();
    if(pgs->query_renegade() == 0){
      write("This player has not been branded a renegade.\n");
      return 1;
    }
    if(unban_pla->query_immortal()){
      write("You can not unban a banned wizard.  Only the GM can do that.\n");
      return 1;
    }
    if(unban_pla->query_real_guild() != 1){
      write("This player is not a thief.\n");
      return 1;
    }
    if(pgs->query_renegade() != 1){
      write("This player is not banned from the guild.\n");
      return 1;
    }
    pgs->set_renegade(0);
    write("You have unbanned "+capitalize(arg)+".\n");
    tell_object(unban_pla,"You are no longer banned from the thieves guild.\n");
    return 1;
}
}
int gabil(){
  write("~~~~Commands for thief guide~~~~\n");
write("ban      This marks a thief as a renegade.  They will be unable to\n"+
"         use the hideout.  Note: This is to be used only when the\n"+
"         thief being banned as broken the thieves code.\n");
  write("unban    This allows a renegade thief to be reinstated as a member\n"+
        "         of the guild.\n");
  return 1;
}
