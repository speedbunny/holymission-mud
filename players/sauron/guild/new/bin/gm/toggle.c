#include "/players/sauron/guild/include/cmd_functions.c"

status main(string str) {
  if(!str) {
    STD_FAIL;
    return 0;
  }
  switch(str) {
    case "guild_log_notify":
    case "gln":
      set("guild_log_notify",!query("guild_log_notify"));
      printf("You will now %sbe notified of any guild log additions.\n",
             (status)query("guild_log_notify")?"":"not ");
      return 1;
      break;
    default:
      NF("Invalid option to 'toggle'.\n");
      return 0;
      break;
  }
}
