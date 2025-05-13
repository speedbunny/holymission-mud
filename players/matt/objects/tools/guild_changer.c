inherit "/obj/thing";

#include "/players/matt/defs.h"

#define GM "/guild/master"

reset(arg) {
  ::reset(arg);
  set_name("/guild changer");
  set_short("Guild changer");
  set_long("This is a magical guild-changer. To change your guild, just\n" +
	   "type \"change <guild-number>\". Enjoy!    - Matt\n");
  set_alias("/guild-changer");
  set_alt_name("changer");
}

init() {
  ::init();
  add_action("change", "change");
}

change(arg) {
  int guild;
  if(arg && sscanf(arg, "%d", guild)) {
    if((guild >= 0) && (guild <= (GM->query_nog() - 1))) {
      write("You change your guild to " + CAP(GM->query_name(guild)) + ".\n");
      TP->set_guild(guild);
      return 1;
    }
    write("That is not a valid guild number.\n");
    return 1;
  }
  write("Change what?\n");
  return 1;
}

drop() { return 1; }

query_auto_load() { return OBJS + "tools/guild_changer:"; }
