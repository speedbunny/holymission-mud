
#define DIR(action) "/players/wilbie/clan/actions/" + action + ".c"
#define ACTION(action) "_" + action

mapping clan_info;

int actions (string str, object *pendant)
{
   string action, arg;
  

    if (!clan_info)
     clan_info = ([ "SH", "clan", "mpose","cwho", "clanoff", "mgrin",
  "bow","titleset","hmm","mlaugh","mques","givit","msad","mpray" ]);
    if (!str) return (0);
    sscanf(str, "%s %s", action, arg);
    if (!arg) action = str;
    if (!member(clan_info, action)) return (0);
    action = ACTION(action);

    return (call_other(DIR(action), action, arg, pendant));
}




