id(string str) {return str=="hb";}
short() {return "hb";}
long() {write("A hb\n"); return 1;}
init() {
  add_action("hb","hb");
  return 1;
}
get(){ return 1; }
hb(){
string f, *a, x, y;
int i;

f=read_file("/obj/player.c");
a=explode(f, "\n");
write(sizeof(a)+"\n");
for(i=0; i<sizeof(a); i++) {
  if(sscanf(a[i],"%sobj%s",x,y)==2) write(a[i]+"\n");
}
return 1;
}
