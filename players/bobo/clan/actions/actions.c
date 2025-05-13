
#define DIR(action) "/players/bobo/clan/actions/" + action + ".c"
#define ACTION(action) "_" + action

mapping clan_info;

int actions (string str, object *amulet)
{
   string action, arg;
  

    if (!clan_info)
     clan_info = ([ "question", "cl", "cm", "clanoff", "boast",
                    "sit","worship", "flog", "petition", "bask",
                    "nourish", "suggestion", "blind", "settitle",
		    "givit", "pat", "wait", "bpose", "wpose",
                    "chide", "mumble", "huh", "ignore", "listen", "wlisten" ]);
    if (!str) return (0);
    sscanf(str, "%s %s", action, arg);
    if (!arg) action = str;
    if (!member(clan_info, action)) return (0);
    action = ACTION(action);

    return (call_other(DIR(action), action, arg, amulet));
}





