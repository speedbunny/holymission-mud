view(str) {
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
