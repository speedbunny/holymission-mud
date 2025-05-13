inherit "/obj/armour";
 
int zone;
string date,time;
 
reset(arg) {
::reset(arg);
if (arg) return;
 set_alias("rockwatch");
 set_name("watch");
 set_short("A rockwatch");
 set_long("A rockwatch made of granit.\n"+
   "Type 'help watch' for further details.\n");
 set_value(10);
 set_weight(1);
 set_type("clock");
 set_size(0);
 set_ac(0);
 zone=1;
}
 
init() {
::init();
  add_action("help","help");
  add_action("show","show");
  add_action("turn","turn");
}
 
help(str) {
  if(!id(str)) return 0;
  cat("/players/kelly/obj/watch.txt");
  return 1;
}
 
show(str) {
  if(str=="time") {
    set_time();
    write("Your clock shows "+time);
    return 1;
  }
  if(str=="date") {
    set_time();
    write(date);
    return 1;
  }
  if(str=="zone") {
    check_zone();
    return 1;
  }
}
 
turn(str) {
  string str1,dir;
  if(!str) return;
  if(sscanf(str,"%s %s",str1,dir)!=2) return;
  if(str1!="wheel") return;
  if(dir!="forward" && dir!="backward") return;
  if(dir=="forward") zone++;
  else zone--;
  if(zone<-12) zone=12;
  if(zone>12) zone=-12;
  check_zone();
  return 1;
}
 
check_zone() {
  string out;
  out=0;
  write("Watch at ");
  switch(zone) {
    case  1: out="CET.\n"; break;
    case  0: out="WET(GMT).\n"; break;
    case  2: out="EET.\n"; break;
    case -5: out="Eastern Standard Time\n"; break;
    case -6: out="Central Time Zone\n"; break; 
    case -7: out="Mountain Time\n"; break;
    case -8: out="Pacific Time\n"; break;
    default: out="WET(GMT)"+zone+" hours\n";
  }
  write(out);
}
 
set_time() {
 string ct;

 ct=ctime(time()+3600*(zone-1)); 
 time=extract(ct,11,19)+"\n";
 date="Today's "+extract(ct,0,10)+extract(ct,20)+".\n";
}
 
