
#define DIR(action) "/players/tatsuo/closed/paper/actions/" + action + ".c"
#define ACTION(action) "_" + action

mapping paper_info;

int actions (string str, object *credentials)
{
   string action, arg;
  

    if (!paper_info)
     paper_info = ([ "HM", "bitch", "bastards", "reoff", "flash"
                ]);
    if (!str) return (0);
    sscanf(str, "%s %s", action, arg);
    if (!arg) action = str;
    if (!member(paper_info, action)) return (0);
    action = ACTION(action);

    return (call_other(DIR(action), action, arg, credentials));
}


