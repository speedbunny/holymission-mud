id(str) { return str=="sayer"; }
short() { return "sayer"; }
get() { return 1; }
init() { add_action("sayer","sayer"); }
sayer() {
  sayer2("a","b");
  return 1;
}

sayer2(v1,v2)
{
  write(v1+v2);
}
