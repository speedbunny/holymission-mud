inherit "/room/room";

string base_long_desc,check,msg;

string extra_desc() {
  if(present(check,this_object()))
    return " "+msg;
  else
    return "";
}

void reset(int arg) {
  ::reset(arg);
  if(!arg)
    long_desc=base_long_desc+"@@extra_desc@@\n";
}
