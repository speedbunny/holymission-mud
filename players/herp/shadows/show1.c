id(str) { if (str=="show") return 1;  else return 0; }
short() {return "show";}
long() {"Shadow Monitor\n"; }
init() {
add_action("show"); add_verb("view");
}

show(str) {
object obj;
string fn;
if (find_living(str)) {
write(capitalize(str)+":  ");
  obj=shadow(find_living(str),0);
  if (!obj) {write("Not Shadowed\n"); return 1;}
  fn = file_name(obj);
  write("Shadowed by:  "+fn+"\n");
	return 1;
}
return 1;
}
