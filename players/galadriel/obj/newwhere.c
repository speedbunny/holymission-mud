/* 9-SEP-93 Galadriel: log players with unknown ip */
/* 14-SEP-93 Galadriel: removed log of result, removed log of environment, */
/* added log of ip name, added log of time, */
/* split in two files for old and new players. */
#define WHEREFROM ("/players/helenette/secure/wherefrom")

string logname;

init() {
  object ob;
  string result;
  
  if(!logname)
    switch(file_name(environment(this_object()))) {
      case "race/room"   : logname="galadriel.where_race"; break;
      case "room/church" : logname="galadriel.where_church"; break;
    }
  ob=this_player();
  result=(WHEREFROM->wherefrom(ob));
  if(result[0..0]=="#")
    log_file(logname,ob->query_real_name()+" "+
                     query_ip_number(ob)+" "+
                     query_ip_name(ob)+" "+
                     ctime(time())+"\n");
  return 1;
}
