
#define DIR(action) "/players/tatsuo/clan/actions/" + action + ".c"
#define ACTION(action) "_" + action

mapping clan_info;

int actions (string str, object *hachimaka)
{
   string action, arg;
  

    if (!clan_info)
     clan_info = ([ "SH", "clan", "cwho", "clanoff", "ego",
   "lovebomb", "mstamp", "hatebomb", "timeout", 
  "chide","woo",
  
"bow","titleset","hmm","bslap","tri","givit","baha","lovebomb","cpose" ]);
    if (!str) return (0);
    sscanf(str, "%s %s", action, arg);
    if (!arg) action = str;
    if (!member(clan_info, action)) return (0);
    action = ACTION(action);

    return (call_other(DIR(action), action, arg, hachimaka));
}




