catch_tell(str) {
  string who, what, dummy;
  if(sscanf(str, "%s says: %s", who, what) == 2) {
    what = lower_case(what);
    who = lower_case(who);
    if(sscanf(what, "%shelp you%s", dummy, dummy) == 2)
      receive_say(who);
  }
}
