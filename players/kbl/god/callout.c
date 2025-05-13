mixed *ob;
int i;

status c_o_2(string str);

status id(string str) {
  return str=="callout" || str=="util" || str=="callout util";
}

status get() {
  return 1;
}

status drop() {
  return 1;
}

string short() {
  return "Callout util";
}

void long() {
  write("Callout util. Use with \"callout\".\n");
}

void init() {
  add_action("callout","callout");
}

string query_auto_load() {
  return "players/kbl/god/callout:";
}

status callout() {
  write("Call_out info ...\n");
  ob=call_out_info();
  i=0;
  c_o_2("");
  return 1;
}

status c_o_2(string str) {
  if(str=="q")
    return 1;
  while(i<sizeof(ob)) {
    if(ob[i]) {
      write(ob[i][1]);
      write(" ");
      write(ob[i][0]);
      write(" ");
      write(ob[i][2]);
    }
    else
      write("N/A ?");
    write("\n");
    i++;
    if(i%18==0) {
      write("<q> to quit, <enter> for more.");
      input_to("c_o_2");
      return 1;
    }
  }
  write(sizeof(ob)+" call_out(s) in total.\n");
  return 1;
}
