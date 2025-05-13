/* TOILET.C - Programmed by Ethereal Cashimor */
/* 210793: Started programming */

inherit "room/room";
#include "/obj/lw.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Toilet";
    long_desc="This is small, dark chamber. There is a wooden bench here with "
            + "a hole in it.\n";
    smell="It stinks here. The smell seems to be coming from the hole.";
    items=({"bench","It can be used as a toilet",
            "hole","It's dark down there. You hear water streaming"});
    dest_dir=({"players/cashimor/extend/cellar","west"});
    set_light(1);
  }
}

init() {
  ::init();
  add_action("sit_it","sit");
  add_action("enter_it","enter");
}

sit_it(str) {
  if((!str)||(str!="bench")) {
    notify_fail("Sit where?\n");
    return 0;
  }
  write(lw("You sit down on the bench. You dispose yourself of the tension in "
      + "your body. You feel very relaxed. After a while you stand up "
      + "again.\n"));
  say(lw(this_player()->query_name()+" sits down on the bench. "
    + capitalize(this_player()->query_pronoun())+" disposes "
    + this_player()->query_objective()+"self of the tension in "
    + this_player()->query_possessive()+" body. "
    + capitalize(this_player()->query_pronoun())+" seems to feel very relaxed."
    + " After a while "+this_player()->query_pronoun()+" stands up again.\n"));
  return 1;
}

enter_it(str) {
  if((!str)||(str!="hole")) {
    notify_fail("Enter what?\n");
    return 0;
  }
  write("You really don't want to do that.\n");
  return 1;
}

