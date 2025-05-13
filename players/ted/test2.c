inherit "room/room";

reset(arg) {
  ::reset(arg);
  short_desc = "Test Time room";
  long_desc = "Test Time Room\n";
}

init() {
  ::init();
  add_action("time1"); add_verb("time1");
 add_action("time2"); add_verb("time2");
}

time1() {
  string day, month;
  int date, hour, min, sec, year;

 if(sscanf(ctime(time()),"%s %s %d %d:%d:%d %d",day,month,date,hour,min,sec,year) == 7) {
   write("Day: "+day+"\n");
   write("month: "+month+"\n");
   write("date: "+date+"\n");
   write("hour: "+hour+"\n");
   write("min: "+min+"\n");
   write("sec: "+sec+"\n");
   write("year: "+year+"\n");
  }
write(ctime(time())+"\n");
  return 1;
}
 
time2() {
  write(time()+"\n");
  return 1;
}
