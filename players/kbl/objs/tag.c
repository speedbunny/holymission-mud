inherit "obj/treasure";

#include "/obj/descs.h"                         /* pat (look at vitals) */

int old_xp,guild,hidden;

reset(arg) {
  if(!arg) {
    set_id("tag");
    set_value(0);
    set_weight(0);
    set_short("A tag");
    set_long("This tag can provide information on experience.\n"
           + "There's something written upon it.\n");
    set_info("Cashimor's experience tag.");
    set_read("Possible commands are:\n\n"
           + "xp: Gives your current xp value\n"
           + "cmp: Gives the difference between last and this xp value\n"
           + "rst: Resets the compare value in the tag\n"
           + "next: Gives the xp still needed for the next level\n"
           + "      Give option 'min' for minimal amount needed\n"
           + "tear: Destroys the tag\n"
           + "hide: Makes the tag invisible\n"
           + "vital: Gives brief display of your hp's and sp's\n"
           + "search: Finds the tag after you've hidden it\n");
  }
}

init() {
  ::init();
  add_action("show_xp","xp");
  add_action("tear","tear");
  add_action("compare","cmp");
  add_action("next_xp","next");
  add_action("reset_xp","rst");
  add_action("hide_it","hide");
  add_action("search","search");
  add_action("show_short","vital");
  old_xp=this_player()->query_exp();
}

short() {
  if(hidden) return 0;
  return ::short();
}

hide_it(str) {
  if(str!="tag") return 0;
  if(!present(this_object(),this_player())) return 0;
  if(hidden) {
    write("But it's already hidden!\n");
    return 1;
  }
  write("You hide the tag.\n");
  say(this_player()->query_name()+" hides a tag.\n");
  hidden=1;
  return 1;
}

/* ----------------------------------------------------------------- */
/* changed by pat (0606'93) according to the new hp/sp display-system */
/* ----------------------------------------------------------------- */
show_short()
{
  object tp;

  tp = this_player();
  say(tp->query_name()+" checks the tag for vital stats.\n");
  write("You see the following vital stats:\n"+
        " Hit points:   "+health_desc(tp->query_maxhp(),tp->query_hp())+"\n"+
        " Spell points: "+mana_desc(tp->query_maxsp(),tp->query_sp())+"\n");
  return 1;
}

search(str) {
  if(str!="tag") return 0;
  if(!present(this_object(),this_player())) return 0;
  if(!hidden) {
    write("But it wasn't hidden!\n");
    return 1;
  }
  write("You find the tag again.\n");
  say(this_player()->query_name()+" finds a tag.\n");
  hidden=0;
  return 1;
}

reset_xp() {
  write("You reset the compare value of the tag.\n");
  say(this_player()->query_name()+" modified a tag.\n");
  old_xp=this_player()->query_exp();
  return 1;
}

tear(str) {
  if(str!="tag") return 0;
  if(!present(this_object(),this_player())) return 0;
  write("You tear the tag to shreds.\n");
  say(this_player()->query_name()+" tears a tag to shreds.\n");
  destruct(this_object());
  return 1;
}

show_xp() {
  write("Your experience is: "+this_player()->query_exp()+".\n");
  say(this_player()->query_name()+" looks at a tag.\n");
  return 1;
}

compare() {
  write("Your increase is: "+(this_player()->query_exp()-old_xp)+".\n");
  say(this_player()->query_name()+" looks at a tag.\n");
  return 1;
}

next_xp(str) {
int bexp,gexp;

  guild=this_player()->query_guild();
  if(this_player()->query_level()>="guild/master"->query_levels(guild)) {
    write("The tag is empty.\n");
    say(this_player()->query_name()+" looks at an empty tag.\n");
    return 1;
  }
  bexp="guild/master"->query_exp(guild,this_player()->query_level());
  gexp="guild/master"->query_exp(guild,this_player()->query_level()+1);
  if(str=="min") {
    gexp=bexp+((gexp-bexp)*9)/10;
  }
  say(this_player()->query_name()+" looks at a tag.\n");
  gexp=gexp-this_player()->query_exp();
  if(gexp<0) {
    write("You can already advance level!\n");
    return 1;
  }
  write("Experience needed for the next level: "+gexp+".\n");
  return 1;
}

drop(silently) {
  return 1;
}

query_auto_load() {
  return "players/kbl/objs/tag:";
}

prevent_insert() {
  return 1;
}
