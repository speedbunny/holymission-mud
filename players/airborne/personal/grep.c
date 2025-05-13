inherit "players/moonchild/std/object";

void reset(int arg) {
  if(arg) return;
  set("short", "Grep tool");
  set("long", "Grep tool. Use: \"grep <expression> <directory/files>\".\n");
  set("name", "grep");
}

string query_auto_load() {
  return "players/airborne/personal/grep:";
}

status drop() {
  return 1;
}

void init() {
  add_action("grep", "grep");
}

status grep(string str) {
  string exp,dir,pathname,*tmp,*files;
  int i,j;
  if(!str) return 0;
  if(sscanf(str, "%s %s", exp, dir)!=2) {
    write("Invalid syntax.\n");
    return 1;
  }
  if(dir[0..0]!="/")
    dir="/" + (string)this_player()->query_path() + "/" + dir;
  tmp=explode(dir, "/");
  tmp=del_array(tmp, sizeof(tmp)-1);
  pathname=implode(tmp, "/");
  if(pathname[-1..-1]!="/") pathname+="/";
  files=get_dir(dir);
  if(!(j=sizeof(files))) {
    write("No files.\n");
    return 1;
  }
  for(i=0;i<j;i++) {
    string file;
    if(file!="." && file!="..") {
      file=read_file(pathname + files[i]);
      if(file && sizeof(explode(file, exp)) > 1)
	write("Found " + exp + " in: " + pathname + files[i] + "\n");
    }
  }
  return 1;
}
